# LLDB Usage

```bash
# 编译器 Clang，调试 main
clang++ main.cc -o main -g

# LLDB
lldb main
breakpoint set --line <num>
breakpoint set --name main   # 函数断点
breakpoint set --method foo  # 类方法断点
breakpoint list 

run  # 执行程序
next
step/finish  # 步入/步出
continue  # 执行到下一个断点

po/p  # 输出变量
frame var -L <variable>  # 打印变量地址

```

