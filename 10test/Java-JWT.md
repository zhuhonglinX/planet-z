# Java JWT

## 什么是 JWT

JWT 全称 JSON web Token，因此他的本质是一个token，只是它是具有统一格式和操作步骤的 token，也就是一种规范，通过这个工具，我们可以在客户端和服务器安全的传输信息。主要是具有验证身份的作用。

关于更多的 JWT 的基本信息可以参考下方链接:

* [八幅漫画理解使用JSON Web Token设计单点登录系统](http://blog.leapoahead.com/2015/09/07/user-authentication-with-jwt/)
* [JWT wiki](https://en.wikipedia.org/wiki/JSON_Web_Token)

因此在这里我只是简单描述 JWT 的构成和实现原理，主要叙述一下我在学习 java 后台开发的时候，如何理解和使用 JWT。

## JWT 构成和原理

构造很简单，一个完整 JWT。主要由三部分构成：
```
header.payload.signature
```
为什么我这里每个部分都用 ``.`` 隔开呢，因为网络中真实传递的 JWT 真的是这种样子的。比如下面这种
```
eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJzdWIiOiIxMjM0NTY3ODkwIiwibmFtZSI6IkpvaG4gRG9lIiwiaWF0IjoxNTE2MjM5MDIyfQ.XbPfbIHMI6arZ3Y922BhjWgQzWXcXNrz0ogtVhfEd2o
```

当然了，每个部分都经过了一些处理，才长了这么奇怪的样子。
header 主要是描述一下，我这个是什么类型的token，用了什么样的加密方法，如：
```
{
  "alg": "HS256",
  "typ": "JWT"
}
```
payload 包含 claims (官方)，我的理解就是里面包含了一些身份信息，比如这个 JWT 的签发者，接受者，有效时间等等， 如：
```
{
  "sub": "1234567890",
  "name": "John Doe",
  "admin": true
}
```
signature 这个是最为关键的一个部分，他用来确保前面的两项不会被他人篡改，假冒。

生成一个 JWT 的流程如下（服务端的角度）：
1. 构建一个正常的 header A，写入一些信息，然后使用 base64 编码 header A 得到 header B
2. 构建一个正常的 payload A，写入一些信息，然后使用 base64 编码 payload A 得到 payload B
3. 选择一个加密算法，如 HS256，然后自定一个 secret，这个 secret 是他人都不知道的，只要本服务端保有
4. 拼接 headerB 和 payloadB 为 headerB.payloadB，将其作为一个整体，使用 HS256 进行加密(secret 为密钥)，从而得到 signature A
5. 把 signature A 用 base64 编码得到 signature B，所以最后的结果就是 headerB.payloadB.signatureB

至此，一个 JWT 就生成完成了。

那么在实际中，它是如何实现身份验证的呢。
首先客户端第一次登录，在确认无误后，服务端生成 JWT 发送到给客户端，客户端需要保存这个 token，之后的请求，如果是有身份要求的请求，就需要带上 JWT 发请求。

服务端这个时候接受到了客户端的请求和 JWT，首先对 JWT 三个部分 headerB，payloadB，signatureB 分别 base64 解码，得到 headerA，payloadA 和 signatureA，这样可以顺利的读取 headerA 和 payloadA 的信息。之前说到，一些用户的信息是放在 payloadA 中的，因此服务端以此暂时认定用户的身份，接着，服务端就要开始验证这个身份是不是有效的，正确的，无篡改的。

服务端通过 headerA 中包含的算法，或者自定的一种算法也行（只要和签发 JWT 时的算法一样就行），这里比如还是 HS256 算法，用该算法带密钥 secret 加密 headerB.payloadB，得到的结果和 signatureA 比较，只要不一样，说明 JWT 不合法，要么是伪造的，要么是篡改的。
这里的加密算法必须能够保证：通过同一个 secret 为密钥，加密 X 一定可以得到唯一的 Y。并且这种映射关系随着 secret 不同而不同。
如果 JWT 被篡改，由于他人不知道 secret，因此加密后的到的结果一定和 signatureA 不同（相同的概率几乎没有）

因此 JWT 非常适合用于身份认证，授权系统等


## java 中使用 JWT

java 后台中可以引入 java-jwt 这个包。

我们可以在 login controller 下调用颁发 JWT 的 service， 如下：

```java
// Controller
@RequestMapping(value = "/login", method = RequestMethod.POST)
    public String login(@RequestParam(value = "username") String username,
                        @RequestParam(value = "password") String passwd) {
        return authService.loginValidation(username, passwd);
    }

// Service
public String loginValidation(String username, String passwd) {
    if (...) {  // username 和 password 都合法
        String token = getToken();
        ....
    }
}
public String getToken() {
    String token = "";
    try {
        Algorithm algorithm = Algorithm.ECDSA512("your secret");
        token = JWT.create()
                .withAudience(Config.aud)
                .sign(algorithm);
    } catch (UnsupportedEncodingException exception) {

    } catch (JWTCreationException exception) {

    }
    return token;
}
```

验证 JWT，如下：
```java
// 某方法
{
    if (token == null) {
        throw new RuntimeException(Config.errLogin);
    }
    // 假设只有 audience
    String audience;
    try {
        audience = JWT.decode(token).getAudience().get(0);
    } catch (JWTDecodeException e) {
        throw new RuntimeException(Config.errLogin);
    }

    if (!audience.equals(Config.aud)) {
        throw new RuntimeException(Config.errLogin);
    }

    try {
        JWTVerifier verifier = JWT.require(Algorithm.ECDSA512(Config.username + Config.passwd)).build();
        try {
            verifier.verify(token);
        } catch (JWTVerificationException e) {
            throw new RuntimeException(Config.errLogin);
        }
    } catch (UnsupportedEncodingException e) {

    }
}
```

如果使用的是 spring 系列的框架
为了实现指定的请求，在业务处理前先进行身份验证，我们可以自定义一个注解，然后用 AOP 的方式实现。

```java
// 自定义注解
@Target(ElementType.METHOD)
@Retention(RetentionPolicy.RUNTIME)
public @interface LoginRequired {
}

// aop
@Aspect
@Component
public class LoginAspect {

    @Pointcut(value = "@annotation(***.***.LoginRequired)")
    public void loginPoint() {

    }

    @Before("loginPoint()")
    public void before() throws Exception{
        // 此处放入验证代码即可
    }
}
```

Target METHOD 表示这个注解是用在方法上的。

Retention Runtime 运行时刻读取使用

Pointcut 指定哪里切入，后面定义，从有 LoginRequired 注解的方法切入，annotation里面是这个注解定义的路径

Before 先执行 aop 的代码，结束后，再执行原函数代码。



---

***2018-03-24***



