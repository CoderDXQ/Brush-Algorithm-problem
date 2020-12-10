cmake_minimum_required(VERSION 3.17)
project(Brush_Algorithm_problem)

set(CMAKE_CXX_STANDARD 14)

add_executable(Brush_Algorithm_problem
        PAT_Code-master/A1001.cpp
        PAT_Code-master/A1002.cpp
        PAT_Code-master/A1003.cpp
        PAT_Code-master/A1004（BFS版本）.cpp
        PAT_Code-master/A1004（DFS版本）.cpp
        PAT_Code-master/A1005.cpp
        PAT_Code-master/A1006.cpp
        PAT_Code-master/A1007.cpp
        PAT_Code-master/A1008.cpp
        PAT_Code-master/A1009.cpp
        PAT_Code-master/A1010.cpp
        PAT_Code-master/A1011.cpp
        PAT_Code-master/A1012.cpp
        PAT_Code-master/A1013（图的遍历（DFS））.cpp
        PAT_Code-master/A1013（并查集）.cpp
        PAT_Code-master/A1014.cpp
        PAT_Code-master/A1015.cpp
        PAT_Code-master/A1016.cpp
        PAT_Code-master/A1017.cpp
        PAT_Code-master/A1018.cpp
        PAT_Code-master/A1019.cpp
        PAT_Code-master/A1020.cpp
        PAT_Code-master/A1021.cpp
        PAT_Code-master/A1022.cpp
        PAT_Code-master/A1023.cpp
        PAT_Code-master/A1024.cpp
        PAT_Code-master/A1025.cpp
        PAT_Code-master/A1026.cpp
        PAT_Code-master/A1027.cpp
        PAT_Code-master/A1028.cpp
        PAT_Code-master/A1029.cpp
        "PAT_Code-master/A1030（Dijkstra + DFS）.cpp"
        PAT_Code-master/A1030（Dijkstra算法）.cpp
        PAT_Code-master/A1031（二维数组方式）.cpp
        PAT_Code-master/A1031（直接输出方式）.cpp
        PAT_Code-master/A1032.cpp
        PAT_Code-master/A1033.cpp
        PAT_Code-master/A1034.cpp
        PAT_Code-master/A1035.cpp
        PAT_Code-master/A1036.cpp
        PAT_Code-master/A1037.cpp
        PAT_Code-master/A1038.cpp
        PAT_Code-master/A1039.cpp
        PAT_Code-master/A1040.cpp
        PAT_Code-master/A1041.cpp
        PAT_Code-master/A1042.cpp
        PAT_Code-master/A1043.cpp
        PAT_Code-master/A1044.cpp
        PAT_Code-master/A1045（最长不下降子序列（LIS））.cpp
        PAT_Code-master/A1045（最长公共子序列（LCS））.cpp
        PAT_Code-master/A1046.cpp
        PAT_Code-master/A1047.cpp
        "PAT_Code-master/A1048（two pointers）.cpp"
        PAT_Code-master/A1048（二分查找）.cpp
        PAT_Code-master/A1048（哈希法）.cpp
        PAT_Code-master/A1049.cpp
        PAT_Code-master/A1050.cpp
        PAT_Code-master/A1051.cpp
        PAT_Code-master/A1052.cpp
        PAT_Code-master/A1053.cpp
        PAT_Code-master/A1054.cpp
        PAT_Code-master/A1055.cpp
        PAT_Code-master/A1056.cpp
        PAT_Code-master/A1057.cpp
        PAT_Code-master/A1058.cpp
        PAT_Code-master/A1059.cpp
        PAT_Code-master/A1060.cpp
        PAT_Code-master/A1061.cpp
        PAT_Code-master/A1062.cpp
        PAT_Code-master/A1063.cpp
        PAT_Code-master/A1064.cpp
        PAT_Code-master/A1065.cpp
        PAT_Code-master/A1066.cpp
        PAT_Code-master/A1067.cpp
        PAT_Code-master/A1068.cpp
        PAT_Code-master/A1069.cpp
        PAT_Code-master/A1070.cpp
        PAT_Code-master/A1071.cpp
        PAT_Code-master/A1072.cpp
        PAT_Code-master/A1073.cpp
        PAT_Code-master/A1074.cpp
        PAT_Code-master/A1075.cpp
        PAT_Code-master/A1076.cpp
        PAT_Code-master/A1077.cpp
        PAT_Code-master/A1078.cpp
        PAT_Code-master/A1079.cpp
        PAT_Code-master/A1080.cpp
        PAT_Code-master/A1081.cpp
        PAT_Code-master/A1082.cpp
        PAT_Code-master/A1083.cpp
        PAT_Code-master/A1084.cpp
        "PAT_Code-master/A1085（two pointers）.cpp"
        PAT_Code-master/A1085（二分查找（使用upper_bound函数））.cpp
        PAT_Code-master/A1085（二分查找）.cpp
        PAT_Code-master/A1086.cpp
        "PAT_Code-master/A1087（使用Dijkstra + DFS）.cpp"
        PAT_Code-master/A1087（只使用Dijkstra）.cpp
        PAT_Code-master/A1088.cpp
        PAT_Code-master/A1089.cpp
        PAT_Code-master/A1090.cpp
        PAT_Code-master/A1091.cpp
        PAT_Code-master/A1092.cpp
        PAT_Code-master/A1093.cpp
        PAT_Code-master/A1094.cpp
        PAT_Code-master/A1095.cpp
        PAT_Code-master/A1096.cpp
        PAT_Code-master/A1097.cpp
        PAT_Code-master/A1098.cpp
        PAT_Code-master/A1099.cpp
        PAT_Code-master/A1100.cpp
        PAT_Code-master/A1101.cpp
        PAT_Code-master/A1102.cpp
        PAT_Code-master/A1103.cpp
        PAT_Code-master/A1104.cpp
        PAT_Code-master/A1105.cpp
        PAT_Code-master/A1106.cpp
        PAT_Code-master/A1107.cpp
        PAT_Code-master/A1108.cpp
        PAT_Code-master/A1109.cpp
        PAT_Code-master/A1110.cpp
        PAT_Code-master/A1111.cpp
        PAT_Code-master/A1112.cpp
        PAT_Code-master/A1113.cpp
        PAT_Code-master/A1114.cpp
        PAT_Code-master/A1115.cpp
        PAT_Code-master/A1116.cpp
        PAT_Code-master/A1117.cpp
        PAT_Code-master/A1118.cpp
        PAT_Code-master/A1119.cpp
        PAT_Code-master/A1120.cpp
        PAT_Code-master/A1121.cpp
        PAT_Code-master/A1122.cpp
        PAT_Code-master/A1123.cpp
        PAT_Code-master/B1001.cpp
        PAT_Code-master/B1002.cpp
        PAT_Code-master/B1003.cpp
        PAT_Code-master/B1004.cpp
        PAT_Code-master/B1005.cpp
        PAT_Code-master/B1006.cpp
        PAT_Code-master/B1007.cpp
        PAT_Code-master/B1008（方法一）.cpp
        PAT_Code-master/B1008（方法二）.cpp
        PAT_Code-master/B1009.cpp
        PAT_Code-master/B1010.cpp
        PAT_Code-master/B1011.cpp
        PAT_Code-master/B1012.cpp
        PAT_Code-master/B1013（方法一：暴力）.cpp
        PAT_Code-master/B1013（方法二：筛法）.cpp
        PAT_Code-master/B1014.cpp
        PAT_Code-master/B1015.cpp
        PAT_Code-master/B1016.cpp
        PAT_Code-master/B1017.cpp
        PAT_Code-master/B1018.cpp
        PAT_Code-master/B1019.cpp
        PAT_Code-master/B1020.cpp
        PAT_Code-master/B1021.cpp
        PAT_Code-master/B1022.cpp
        PAT_Code-master/B1023.cpp
        PAT_Code-master/B1024.cpp
        PAT_Code-master/B1025.cpp
        PAT_Code-master/B1026.cpp
        PAT_Code-master/B1027.cpp
        PAT_Code-master/B1028.cpp
        PAT_Code-master/B1029.cpp
        "PAT_Code-master/B1030（two pointers）.cpp"
        PAT_Code-master/B1030（二分查找（使用upper_bound函数））.cpp
        PAT_Code-master/B1030（二分查找）.cpp
        PAT_Code-master/B1031.cpp
        PAT_Code-master/B1032.cpp
        PAT_Code-master/B1033.cpp
        PAT_Code-master/B1034.cpp
        PAT_Code-master/B1035.cpp
        The_sword_refers_to_offer/0~n-1中缺失的数字.cpp
        The_sword_refers_to_offer/1~n整数中1出现的次数.cpp
        The_sword_refers_to_offer/n个骰子的点数.cpp
        The_sword_refers_to_offer/Singleton.cpp
        The_sword_refers_to_offer/不用加减乘除做加法.cpp
        The_sword_refers_to_offer/丑数.cpp
        The_sword_refers_to_offer/两个链表的第一个公共节点.cpp
        The_sword_refers_to_offer/二叉搜索树与双向链表.cpp
        "The_sword_refers_to_offer/二叉搜索树的后序遍历序列(1).cpp"
        The_sword_refers_to_offer/二叉搜索树的第k大节点.cpp
        "The_sword_refers_to_offer/二叉树中和为某一值的路径(1).cpp"
        The_sword_refers_to_offer/二叉树的下一个节点.cpp
        The_sword_refers_to_offer/二叉树的深度.cpp
        The_sword_refers_to_offer/二叉树的镜像.cpp
        The_sword_refers_to_offer/二维数组中的查找.cpp
        The_sword_refers_to_offer/二进制中1的个数.cpp
        The_sword_refers_to_offer/从上到下打印二叉树.cpp
        The_sword_refers_to_offer/从头到尾打印链表.cpp
        The_sword_refers_to_offer/删除链表中重复的节点.cpp
        The_sword_refers_to_offer/删除链表的节点.cpp
        The_sword_refers_to_offer/剪绳子.cpp
        The_sword_refers_to_offer/包含min函数的栈.cpp
        The_sword_refers_to_offer/反转链表.cpp
        The_sword_refers_to_offer/合并两个排序的链表.cpp
        The_sword_refers_to_offer/和为s的两个数字.cpp
        The_sword_refers_to_offer/和为s的连续正数序列.cpp
        The_sword_refers_to_offer/圆圈中最后剩下的数字.cpp
        The_sword_refers_to_offer/复杂链表的复制.cpp
        The_sword_refers_to_offer/字符串的排列.cpp
        The_sword_refers_to_offer/字符流中第一个只出现一次的字符.cpp
        The_sword_refers_to_offer/对称的二叉树.cpp
        The_sword_refers_to_offer/左旋转字符串.cpp
        The_sword_refers_to_offer/平衡二叉树.cpp
        The_sword_refers_to_offer/序列化二叉树.cpp
        The_sword_refers_to_offer/快速排序.cpp
        The_sword_refers_to_offer/扑克牌中的顺子.cpp
        The_sword_refers_to_offer/打印从1到最大的n位数.cpp
        The_sword_refers_to_offer/把字符串转换成整数.cpp
        The_sword_refers_to_offer/把数字翻译成字符串.cpp
        The_sword_refers_to_offer/把数组排成最小的数.cpp
        The_sword_refers_to_offer/数值的整数次方.cpp
        The_sword_refers_to_offer/数字在排序数组中出现的次数.cpp
        The_sword_refers_to_offer/数字序列中某一位的数字.cpp
        The_sword_refers_to_offer/数据流中的中位数.cpp
        The_sword_refers_to_offer/数组中出现次数超过一半的数字.cpp
        The_sword_refers_to_offer/数组中只出现一次的两个数字.cpp
        The_sword_refers_to_offer/数组中唯一只出现一次的数字.cpp
        The_sword_refers_to_offer/数组中数值和下标相等的元素.cpp
        The_sword_refers_to_offer/数组中的逆序对.cpp
        The_sword_refers_to_offer/数组中重复的数字.cpp
        The_sword_refers_to_offer/旋转数组的最小数字.cpp
        The_sword_refers_to_offer/替换空格.cpp
        The_sword_refers_to_offer/最小的k个数.cpp
        The_sword_refers_to_offer/最长不含重复字符的子字符串.cpp
        The_sword_refers_to_offer/机器人的运动范围.cpp
        The_sword_refers_to_offer/构建乘积数组.cpp
        The_sword_refers_to_offer/栈的压入、弹出序列.CPP
        The_sword_refers_to_offer/树中两个节点的最低公共祖先.cpp
        The_sword_refers_to_offer/树的子结构.cpp
        The_sword_refers_to_offer/正则表达式匹配.cpp
        The_sword_refers_to_offer/求1+2+...+n.cpp
        The_sword_refers_to_offer/滑动窗口的最大值.cpp
        The_sword_refers_to_offer/用两个栈实现队列.cpp
        The_sword_refers_to_offer/用两个队列实现一个栈.cpp
        The_sword_refers_to_offer/矩阵中的路径.cpp
        The_sword_refers_to_offer/礼物的最大价值.cpp
        The_sword_refers_to_offer/第一个只出现一次的字符.cpp
        The_sword_refers_to_offer/翻转单词顺序.cpp
        The_sword_refers_to_offer/股票的最大利润.cpp
        The_sword_refers_to_offer/表示数值的字符串.cpp
        The_sword_refers_to_offer/调整数组顺序使奇数位于偶数前面.cpp
        The_sword_refers_to_offer/赋值.cpp
        The_sword_refers_to_offer/连续子数组的最大和.cpp
        The_sword_refers_to_offer/重建二叉树.cpp
        The_sword_refers_to_offer/链表中倒数第k个节点.cpp
        The_sword_refers_to_offer/链表中环的入口节点.cpp
        The_sword_refers_to_offer/队列的最大值.cpp
        The_sword_refers_to_offer/顺时针打印矩阵.cpp
        洛谷/bitset.cpp
        洛谷/P1009.cpp
        洛谷/P1065.cpp
        洛谷/P1075.cpp
        洛谷/P1125.cpp
        洛谷/P1319.cpp
        洛谷/P1320.cpp
        洛谷/P1765.cpp
        洛谷/P1888.cpp
        洛谷/P2141.cpp
        洛谷/P2181.cpp
        洛谷/P2615.cpp
        洛谷/P2669.cpp
        洛谷/P2670.cpp
        洛谷/P5015.cpp
        洛谷/P5706.cpp
        洛谷/P5709.cpp
        洛谷/tempCodeRunnerFile.cpp
        洛谷/test.cpp
        1001.cpp
        10012.cpp
        1002.cpp
        1004.cpp
        1011.cpp
        1013.cpp
        1014.cpp
        1015.cpp
        1015结构体数值的交换.cpp
        1016.cpp
        1017.cpp
        1018.cpp
        1019.cpp
        1020.cpp
        1021.cpp
        1022.cpp
        1023.cpp
        1024.cpp
        1025.cpp
        1026.cpp
        1027.cpp
        1030结构体数值的交换.cpp
        1080.cpp
        10800000.cpp
        1080多条件快速排序.cpp
        A1001.cpp
        A1002.cpp
        A1003.cpp
        "A1004 bfs.cpp"
        "A1004 dfs.cpp"
        A1004.cpp
        A1005.cpp
        A1006.cpp
        A1008.cpp
        A1009.cpp
        A1010.cpp
        A1011.cpp
        A1012.cpp
        A1013.cpp
        A1015.cpp
        "A1018 DFS+Dijkstra.cpp"
        "A1018 不能只用dj.cpp"
        A1018.cpp
        A1019.cpp
        A1020.cpp
        "A1030 Dijkstra+dfs.cpp"
        "A1030 Dijkstra.cpp"
        A1030a.cpp
        A1032.cpp
        A1034.cpp
        A1043.cpp
        A1052.cpp
        A1053.cpp
        A1076.cpp
        A1094.cpp
        "AC自动机 待学习.cpp"
        CIDR.cpp
        CIDR去重.cpp
        debug.cpp
        "Dijkstra 1.cpp"
        "Dijkstra 2.cpp"
        Dijkstra.cpp
        gdfhdf.cpp
        helloworld.cpp
        jisuanqian.cpp
        jitu.cpp
        jiugongge.cpp
        lianbiao.cpp
        m元分入n个红包.cpp
        "P1029 最大公约数和最小公倍数.cpp"
        "P1030 指针做法.cpp"
        "P1030 静态数组做法.cpp"
        p1030.cpp
        "P1032 另一种写法.cpp"
        p1032.cpp
        "P1035 指针做法.cpp"
        P1035.cpp
        "P1040 记忆化搜索.cpp"
        p1045.cpp
        p1048.cpp
        p1049.cpp
        p1060.cpp
        P1064.cpp
        P1080.cpp
        "p1087 指针做法.cpp"
        "P1087 静态.cpp"
        P1087.cpp
        "P1088 next_permutation.cpp"
        "P1126 bfs.cpp"
        P1126.cpp
        "P1141 DFS+并查集+滚动数组.cpp"
        "P1141 记忆化搜索.cpp"
        "P1160 指针解法.cpp"
        "P1160 数组解法.cpp"
        p1164.cpp
        "P1197 1.cpp"
        "p1197 2.cpp"
        "P1305 非指针解法.cpp"
        p1338.cpp
        P1372.cpp
        "P1403  1.cpp"
        P1403.cpp
        "P1443 dfs.cpp"
        P1443.cpp
        "p1582 2.cpp"
        P1582.cpp
        "P1605 迷宫.cpp"
        P1616.cpp
        P1865.cpp
        P2085.cpp
        P2158.cpp
        "P3366 Kruskal+快排.cpp"
        "P3366 一般思路.cpp"
        "P3366 克鲁斯卡尔+快排 .cpp"
        "P3366 堆优化+Prime+邻接表 .cpp"
        "P3366 堆优化+Prime+邻接表.cpp"
        "P3366克鲁斯卡尔+堆优化 .cpp"
        "P3371 dijkstra+优先队列+前向星+读入输出优化.cpp"
        "P3371 前向星Dijkstra.cpp"
        "P3371 地杰斯特拉.cpp"
        "P3371 堆优化dijkstra.cpp"
        "P3371 简单思路.cpp"
        "P3371 邻接表Dijkstra.cpp"
        "P3371 邻接表SPFA (2).cpp"
        "P3371 邻接表SPFA.cpp"
        "PAT 甲级 1003.cpp"
        "PAT 甲级 1030.cpp"
        "Pp1403  1.cpp"
        "quickSort 1.cpp"
        "quicksort 11.cpp"
        quicksort.cpp
        se.cpp
        set用法.cpp
        "shiti 1.1.cpp"
        "shiti 1.2.cpp"
        "shiti 2.1.cpp"
        "shiti 2.2.cpp"
        shiyan.cpp
        shiyn.cpp
        Shortestcharacterencoding.cpp
        sjiyan.cpp
        ss.cpp
        sshiyan.cpp
        sss.cpp
        ssss.cpp
        sssssss.cpp
        sssygs.cpp
        ssyy.cpp
        sty.cpp
        sy.cpp
        syysgyy.cpp
        syysyy.cpp
        syyy.cpp
        syyyy.cpp
        syyyyyy.cpp
        T1.cpp
        T2.cpp
        T3.cpp
        tempCodeRunnerFile.cpp
        TIHUAN.cpp
        "Trie树 未完成.cpp"
        Unt1.cpp
        Untissyy.cpp
        Untitled2.cpp
        xiugai.cpp
        xor.cpp
        "xor_prefix practice.cpp"
        yyyyy.cpp
        zifuchuantihuan.cpp
        二叉树的静态实现.cpp
        二进制中1的个数.cpp
        从文件中读取数据.cpp
        位运算.cpp
        几个岛.cpp
        利用map实现桶排序.cpp
        剪绳子.cpp
        参数解析.cpp
        反转列表.cpp
        合法ip.cpp
        合法括号序列判断.cpp
        合法括号序列判断1.cpp
        大数进制转换.cpp
        字符串内任意位置翻转.cpp
        字符串分隔.cpp
        字符串的调整.cpp
        带负数的进制转换.cpp
        "并查集 P3367.cpp"
        并查集.cpp
        归并排序的两种实现.cpp
        归并排序递归实现模板.cpp
        循环数比较.cpp
        快速幂.cpp
        快速排序的两种表示.cpp
        数独2.cpp
        方法四作对比DIJKSTRA.cpp
        替换空格.cpp
        最小公倍数.cpp
        最短字符编码1.cpp
        格式处理.cpp
        "模板 高精度乘法.cpp"
        模板.cpp
        "洛谷p1045 进制转换+压位.cpp"
        "洛谷p1045 高精度乘法+压位.cpp"
        "洛谷P1045 高精度乘法+快速幂.cpp"
        "洛谷P1162 DFS .cpp"
        简单DP.cpp
        "素数表线性筛 落谷P3383.cpp"
        约瑟夫问题.cpp
        细节试验.cpp
        结构体+多条件排序.cpp
        结构体快速排序.cpp
        翻转子串.cpp
        "落谷 P1010.cpp"
        "落谷 P1010幂次方.cpp"
        "落谷 P1028.cpp"
        "落谷 P1031.cpp"
        "落谷 P1071.cpp"
        "落谷 P1080.cpp"
        "落谷 P1086.cpp"
        "落谷 P1090.cpp"
        "落谷 P1094.cpp"
        "落谷 P1098.cpp"
        "落谷 P1111.cpp"
        "落谷 P1115.cpp"
        "落谷 P1162.cpp"
        "落谷 P1197 2.cpp"
        "落谷 P1197.cpp"
        "落谷 P1341 Hierholzer.cpp"
        "落谷 P1449.cpp"
        "落谷 P1464 打表方法.cpp"
        "落谷 P1464 递归题.cpp"
        "落谷 P1498 递归.cpp"
        "落谷 p1498.cpp"
        "落谷 P1540 机器翻译.cpp"
        "落谷 P1603.cpp"
        "落谷 P1604.cpp"
        "落谷 P1739.cpp"
        "落谷 P1781.cpp"
        "落谷 P1801.cpp"
        "落谷 P1803.cpp"
        "落谷 P1908.cpp"
        "落谷 P1996.cpp"
        "落谷 P2024.cpp"
        "落谷 P2089 烤鸡.cpp"
        "落谷 P2278.cpp"
        "落谷 P2661 带权路径并查集.cpp"
        "落谷 P2661 并查集.cpp"
        落谷P.cpp
        落谷P1012.cpp
        落谷P1019.cpp
        "落谷p1040 加分二叉树.cpp"
        落谷P1042.cpp
        "落谷P1092 虫食算 高斯消元法.cpp"
        落谷P1101.cpp
        "落谷P1141 DFS+并查集.cpp"
        落谷P1147.cpp
        "落谷P1160 二叉树解法.cpp"
        "落谷P1196 带权并查集.cpp"
        "落谷P1219 八皇后 全排列解法.cpp"
        "落谷P1225 压位.cpp"
        "落谷P1484 种树.cpp"
        落谷P2085.cpp
        "落谷p2661 删边.cpp"
        "落谷P3366 Kruskal+堆优化.cpp"
        落谷P3952.cpp
        输入调整.cpp
        连续非空子串最大和.cpp
        "选数 落谷P1036.cpp"
        邻接表SPFA.cpp
        静态二叉树的实现.cpp
        顺子问题.cpp
        高精度乘法.cpp
        高精度减法.cpp
        高精度加法.cpp
        鸡鸭分类问题.cpp)

add_executable(和为s的两个数字 The_sword_refers_to_offer/和为s的两个数字.cpp)