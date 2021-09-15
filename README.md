## 数据结构与算法分析笔记

*未经允许请勿转载*

作者：jzh

### 0.算法分析

1. 运行时间的计算
2. 运行空间的计算（这个我去查查看CSDN）

### 1.线性表

1. 线性表定义：
2. 线性表顺序存储结构
3. 线性表链式存储结构
   1. 单链表
   
      这个需要勤加练习，一定一定要打的毫无错误（我还是出了一个小错。
   
      ```c++
      #include <iostream>
      using namespace std;
      class listNode
      {
      public:
          int num;
          listNode *next;
      
      public:
          listNode();
          listNode(int tnum, listNode *tnext);
          listNode(int tnum);
          int getNum();
          listNode *getNext();
      };
      
      class list
      {
      private:
          int nodeNum;
          listNode *head;
          listNode *end;
      
      public:
          list();
          listNode *getHead();
          listNode *getEnd();
          listNode *push_end(int tnum);
          int pop_end();
          listNode *insertNode(const int i, const int n);
          listNode *deleteNode(const int i);
          void print();
      };
      listNode::listNode() : num(0), next(nullptr) {}
      listNode::listNode(int tnum, listNode *tnext) : num(tnum), next(tnext) {}
      listNode::listNode(int tnum) : num(tnum), next(nullptr) {}
      int listNode::getNum()
      {
          return num;
      }
      listNode *listNode::getNext()
      {
          return next;
      }
      list::list() : nodeNum(0), head(nullptr), end(nullptr) {}
      listNode *list::getEnd()
      {
          return end;
      }
      listNode *list::getHead()
      {
          return head;
      }
      listNode *list::push_end(int tnum)
      {
          listNode *temp = new listNode(tnum);
          if (nodeNum == 0)
          {
              head = temp;
              end = temp;
              nodeNum++;
          }
          else
          {
              end->next = temp;
              nodeNum++;
              end = temp;
          }
          return head;
      }
      int list::pop_end()
      {
          listNode *temp = end;
          int ans = temp->num;
          listNode *x = head;
          for (int i = 0; i < nodeNum - 2; i++)//这里是-2
          {
              x = x->next;
          }
          end = x;
          nodeNum--;
          delete temp;
          return ans;
      }
      listNode *list::insertNode(const int i, const int n) //后插
      {
          if (n > nodeNum)
          {
              return nullptr;
          }
          listNode *x = head;
          for (int i = 0; i < n - 1; i++)
          {
              x = x->next;
          }
          nodeNum++;
          listNode *in = new listNode(i);
          in->next = x->next;
          x->next = in;
          return head;
      }
      listNode *list::deleteNode(const int i)
      {
          listNode *x = head;
          listNode *befx = head;
          while (x->num != i)
          {
              befx = x;
              x = x->next;
          }
          if (x == end->next)
          {
              return nullptr;
          }
          else if (x == head)
          {
              head = head->next;
              delete x;
              nodeNum--;
              return head;
          }
          else
          {
              befx->next = x->next;
              nodeNum--;
              delete x;
              return head;
          }
      }
      void list::print()
      {
          if (nodeNum != 0)
          {
              listNode *temp = head;
              while (temp != end)
              {
                  cout << temp->num << endl;
                  temp = temp->next;
              }
              cout << temp->num << endl<<endl;
              return;
          }
          else
          {
              cout << "error" << endl;
          }
      }
      int main()
      {
          list test;
          test.push_end(1);
          test.push_end(2);
          test.print();
          int num = test.pop_end();
          cout << num << endl << endl;
          test.print();
          test.push_end(2);
          test.push_end(3);
          test.push_end(4);
          test.print();
          test.deleteNode(3);
          test.print();
          test.insertNode(1,2);
          test.print();
          return 0;
      }
      ```
   
      
   
   2. 循环链表
   
      其实这个只需要将end和head连在一起就可以了
   
      ```c++
      #include <iostream>
      using namespace std;
      class listNode
      {
      public:
          int num;
          listNode *next;
      
      public:
          listNode();
          listNode(int tnum, listNode *tnext);
          listNode(int tnum);
          int getNum();
          listNode *getNext();
      };
      
      class list
      {
      private:
          int nodeNum;
          listNode *head;
          listNode *end;
      
      public:
          list();
          listNode *getHead();
          listNode *getEnd();
          listNode *push_end(int tnum);
          int pop_end();
          listNode *insertNode(const int i, const int n);
          listNode *deleteNode(const int i);
          void print();
      };
      listNode::listNode() : num(0), next(nullptr) {}
      listNode::listNode(int tnum, listNode *tnext) : num(tnum), next(tnext) {}
      listNode::listNode(int tnum) : num(tnum), next(nullptr) {}
      int listNode::getNum()
      {
          return num;
      }
      listNode *listNode::getNext()
      {
          return next;
      }
      list::list() : nodeNum(0), head(nullptr), end(nullptr) {}
      listNode *list::getEnd()
      {
          return end;
      }
      listNode *list::getHead()
      {
          return head;
      }
      listNode *list::push_end(int tnum)
      {
          listNode *temp = new listNode(tnum);
          if (nodeNum == 0)
          {
              head = temp;
              end = temp;
              nodeNum++;
              end->next = head;
          }
          else
          {
              end->next = temp;
              nodeNum++;
              end = temp;
              end->next = head;
          }
          return head;
      }
      int list::pop_end()
      {
          listNode *temp = end;
          int ans = temp->num;
          listNode *x = head;
          for (int i = 0; i < nodeNum - 2; i++)//这里是-2
          {
              x = x->next;
          }
          end = x;
          nodeNum--;
          delete temp;
          end->next = head;
          return ans;
      }
      listNode *list::insertNode(const int i, const int n) //后插
      {
          if (n > nodeNum)
          {
              return nullptr;
          }
          listNode *x = head;
          for (int i = 0; i < n - 1; i++)
          {
              x = x->next;
          }
          nodeNum++;
          listNode *in = new listNode(i);
          in->next = x->next;
          x->next = in;
          //
          return head;
      }
      listNode *list::deleteNode(const int i)
      {
          listNode *x = head;
          listNode *befx = head;
          while (x->num != i)
          {
              befx = x;
              x = x->next;
          }
          if (x == end->next)
          {
              return nullptr;
          }
          else if (x == head)
          {
              head = head->next;
              delete x;
              nodeNum--;
              return head;
          }
          else
          {
              befx->next = x->next;
              nodeNum--;
              delete x;
              return head;
          }
      }
      void list::print()
      {
          if (nodeNum != 0)
          {
              listNode *temp = head;
              while (temp != end)
              {
                  cout << temp->num << endl;
                  temp = temp->next;
              }
              cout << temp->num << endl<<endl;
              return;
          }
          else
          {
              cout << "error" << endl;
          }
      }
      int main()
      {
          list test;
          test.push_end(1);
          test.push_end(2);
          test.print();
          listNode* t = test.getHead();
          for(int i = 0; i < 4; i++)
          {
              cout << t->num << endl;
              t=t->next;
          }
          return 0;
      }
      ```
   
      
   
   3. 双向链表
   
      ```c++
      #include <iostream>
      using namespace std;
      class listNode
      {
      public:
          int num;
          listNode *next;
          listNode *before;
      
      public:
          listNode();
          listNode(int tnum, listNode *tnext, listNode *tbefore);
          listNode(int tnum);
          int getNum();
          listNode *getNext();
          listNode *getbefore();
      };
      
      class list
      {
      private:
          int nodeNum;
          listNode *head;
          listNode *end;
      
      public:
          list();
          listNode *getHead();
          listNode *getEnd();
          listNode *push_end(int tnum);
          int pop_end();
          listNode *insertNode(const int i, const int n);
          listNode *deleteNode(const int i);
          void print();
      };
      listNode::listNode() : num(0), next(nullptr), before(nullptr) {}
      listNode::listNode(int tnum, listNode *tnext, listNode *tbefore) : num(tnum), next(tnext), before(tbefore) {}
      listNode::listNode(int tnum) : num(tnum), next(nullptr), before(nullptr) {}
      int listNode::getNum()
      {
          return num;
      }
      listNode *listNode::getNext()
      {
          return next;
      }
      listNode *listNode::getbefore()
      {
          return before;
      }
      list::list() : nodeNum(0), head(nullptr), end(nullptr) {}
      listNode *list::getEnd()
      {
          return end;
      }
      listNode *list::getHead()
      {
          return head;
      }
      listNode *list::push_end(int tnum)
      {
          listNode *temp = new listNode(tnum);
          if (nodeNum == 0) //first
          {
              head = temp;
              end = temp;
              nodeNum++;
          }
          else
          {
              end->next = temp;
              nodeNum++;
              temp->before = end;
              end = temp;
          }
          return head;
      }
      int list::pop_end()
      {
          listNode *temp = end;
          int ans = temp->num;
          listNode *befEnd = end->before;
          end = befEnd;
          nodeNum--;
          delete temp;
          return ans;
      }
      listNode *list::insertNode(const int i, const int n)
      {
          if (n > nodeNum)
          {
              return nullptr;
          }
          listNode* x = head;
          for (int i = 0; i < n - 1; i++)
          {
              x = x->next;
          }
          nodeNum++;
          listNode *in = new listNode(i);
          in->before = x;
          in->next = x->next;
          x->next = in;
          x->next->before = in;
          return head;
      }
      listNode *list::deleteNode(const int i)
      {
          listNode* x = head;
          while(x->num!=i)
          {
              x = x->next;
          }
          if(x==nullptr)
          {
              return nullptr;
          }
          else if(x == head)
          {
              head = x->next;
              nodeNum--;
              delete x;
              return head;
          }
          else
          {
              listNode* b = x->before;
              b->next = x->next;
              x->next->before = x->before;
              delete x;
              nodeNum--;
              return head;
          }
      }
      void list::print()
      {
          if (nodeNum != 0)
          {
              listNode *temp = head;
              while (temp != end)
              {
                  cout << temp->num << endl;
                  temp = temp->next;
              }
              cout << temp->num << endl
                   << endl;
              return;
          }
          else
          {
              cout << "error" << endl;
          }
      }
      int main()
      {
          list test;
          test.push_end(1);
          test.push_end(2);
          test.print();
          int num = test.pop_end();
          cout << num << endl << endl;
          test.print();
          test.push_end(2);
          test.push_end(3);
          test.push_end(4);
          test.print();
          test.deleteNode(3);
          test.print();
          test.insertNode(1,2);
          test.print();
          return 0;
      }
      ```
   
      
4. 链表提高：链表上层下层

### 2.栈与队列

1. 栈
   1. 栈的定义
   2. 顺序栈
   3. 链式栈
2. 队列
   1. 队列概念
   2. 链队列
   3. 循环队列
   4. 队列提高：优先队列

### 3.串

1. 串的定义
2. 字符串实现
3. 匹配算法
   1. 简单匹配
   2. 首位匹配
   3. KMP匹配
   4. regex实现和使用

### 4.数组与广义表

1. 数组
   1. 数组概念
   2. 数组的顺序存储方式
2. 矩阵
   1. 定义：
   2. 特殊矩阵
   3. <font color=red>稀疏矩阵</font>
3. 广义表
   1. 概念
   2. 实现

### 5.树和二叉树

1. 树的定义：
2. 二叉树
   1. 定义
   2. 实现
   3. 进阶：二叉查找树
3. 二叉树遍历
   1. 前序
   2. 中序
   3. 后序
4. <font color =orange>线索二叉树</font>
   1. 定义
   2. 实现
5. 哈夫曼树
   1. 定义
   2. 实现
6. <font color= red>进阶：AVL树、B树、B+树、红黑树</font>
   1. AVL树
      1. 定义
      2. 实现
   2. B树
      1. 定义
      2. 实现
   3. B+树
      1. 定义
      2. 实现
   4. 红黑树
      1. 定义
      2. 实现

### 6.优先队列

1. 二叉堆
2. d-堆
3. 左式堆
4. 斜堆
5. 二项队列

### 7.图

1. 图的定义
2. 存储方式
   1. 邻接矩阵
   2. 邻接表
3. 并查集
4. 图遍历
   1. DFS
   2. LFS
5. 最小生成树
   1. PRIM算法
   2. KRUSKAL算法
6. <font color=red>有向无环图</font>
   1. 拓扑排序
   2. 关键路径
7. 最短路
   1. Dijkstra算法
   2. 弗洛伊德算法
   3. bellman-ford算法
8. 最大流最小割问题
   1. 最大流
   2. 最小割
9. NP完全性介绍
10. 旅行商问题

### 8. 查找

1. 静态表查找
   1. 无序表查找
   2. 有序表查找
   3. <font color=red>三分法</font>
2. 动态查找
   1. 二叉排序树
   2. 二叉平衡树
   3. B树和B+树
3. 散列表（这个再数据结构黑书中是第5章）
   1. 定义
   2. 实现
   3. 避免冲突（哈希表）
   4. <font color=red>布隆筛</font>（具体可以看b站武僧视频）

### 9.排序

1. 插入排序
2. 希尔排序
3. 冒泡排序
4. 快速排序<font color=red>重要！！！</font>
5. 归并排序
6. 基数排序
   1. 多关键排序
   2. 基数排序
7. 外部排序
8. <font color=orange>桶排序和堆排序</font>
   1. 桶排序
   2. 堆排序

### 10.高级数据结构

1. 自顶向下伸展树
2. 确定性跳跃表
3. AA树
4. treap树
5. k-d树
6. 配对堆

### 11.其他算法

1. 递归算法
2. 分治算法
3. <font color=red>DP动态规划</font>
4. <font color=red>贪心算法</font>
5. 随机化算法
6. 回溯算法
7. 摊还算法
8. 分支限界算法
9. 不相交集ADT

~其他请参照https://oi-wiki.org/~



