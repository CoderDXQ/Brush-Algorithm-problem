在VS Code下使用mingw库编译调试算法题无故出错后，尝试使用`TDM_GCC`替代`mingw`成功。
参考教程 https://www.cnblogs.com/char-cheng/p/11219958.html

###在使用过程中请注意：
调试时至少添加一个断点，否则程序会一闪而过。
一般不要在程序主程序中使用`getchar()`或`system("pause")`来达到上述目的。


----

重要的`tasks.json`文件备案：
```
{
    "version": "2.0.0",
    "command": "g++",
    "args": ["-g","${file}","-o","${fileBasenameNoExtension}.exe"], // 编译命令参数
    "problemMatcher": {
        "owner": "cpp",
        "fileLocation": ["relative", "${workspaceRoot}"],
        "pattern": {
            "regexp": "^(.*):(\\d+):(\\d+):\\s+(warning|error):\\s+(.*)$",
            "file": 1,
            "line": 2,
            "column": 3,
            "severity": 4,
            "message": 5
        }
    }
  }

```

重要的`launch.json`文件备案
```
{
    "version": "0.2.0",
    "configurations": [

        {
            "name": "(gdb) Launch",    // 配置名称，将会在启动配置的下拉菜单中显示
            "type": "cppdbg",         // 配置类型，这里只能为cppdbg
            "request": "launch",    // 请求配置类型，可以为launch（启动）或attach（附加）
            "program": "${workspaceRoot}/${fileBasenameNoExtension}.exe",// 将要进行调试的程序的路径
            "args": [],                // 程序调试时传递给程序的命令行参数，一般设为空即可
            "stopAtEntry": false,     // 设为true时程序将暂停在程序入口处，一般设置为false
            "cwd": "${workspaceRoot}",// 调试程序时的工作目录，一般为${workspaceRoot}即代码所在目录
            "environment": [],
            "externalConsole": true,// 调试时是否显示控制台窗口，一般设置为true显示控制台
            "MIMode": "gdb",
            "miDebuggerPath": "D:\\c_c++GCC\\bin\\gdb64.exe",// miDebugger的路径，注意这里要与MinGw的路径对应
            "preLaunchTask": "g++",    // 调试会话开始前执行的任务，一般为编译程序，c++为g++, c为gcc
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ]
        }
    ]
}
```

----
另外的解决方案：https://www.cnblogs.com/lightmare/p/10428836.html ，但是此方案没机会验证。此方案使用codeblocks自带mingw的特点来避免安装mingw的繁琐。

`C/C++"任务的任务提供程序意外提供了“shell”类型的任务`问题的解决 https://blog.csdn.net/weixin_45348389/article/details/106024975?utm_source=app ，这种方法也没有验证过，因为这个问题我可以忍受。