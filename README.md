# leetcode

2021/9/22

**题目**

修剪二叉搜索树，将值不在界限范围内的节点删除

**思路**

1.返回值及参数

因为要返回树的结构，所以返回值为Treenode类型的，参数为root。

2.终止条件

当root是空节点的时候，返回空。

3.单层递归逻辑

当root的值小于low时，寻找右子树中符合值大于low的节点，将其返回；当root的值大于high时，寻找左子树中符合值小于high的节点，将其返回。递归左右子树。

**题目**

将有序数组转换为二叉搜索树，有序数组是递增的。

**思路**

1.返回值及参数

因为要返回树的结构，所以返回类型为Treenode，因为要有左右边界，所以参数应该有数组、left、right。

2.终止条件

当左边界大于右边界的时候，说明递归结束

3.单层递归逻辑

因为二叉搜索树中序遍历后的数组是递增的，所以数组中间值即为根结点的值。因此求出数组中间索引的值，然后将其指向的数据赋给新声明的根节点，然后左子树的边界为数组的开始到数组中间的前一个数据；右子树的边界为数组中间的后一个数据到数组末尾。

**题目**

把二叉搜索树转换为累加树

**思路**

仔细观察给的示例发现是按照右、中、左的顺序进行累加。因此可以用一个指针记录前一个节点的值，让指针移动以此实现累加。

1.返回值及参数

因为是循环遍历整棵树累加，所以可以没有返回值，参数为root

2.终止条件

当root为空的时候返回空。

3.单层递归逻辑

右递归、当前节点的值累加上一个节点的值，然后将当前结点的值赋给指针、左递归。

2021/9/23

**题目**

组合，将从1到n中的数取k个组成不同的组合，组合没有顺序，因此元素不同顺序排列的组合是同一个，即只要组合内的元素一样，即为同一个组合。

**思路**

从组合为[1,n]中取k个数可以组成多少组合的题目可以使用回溯法。如果使用嵌套for循环时，需要有k层for循环，因此，for循环方法不可行。虽然回溯法也是暴力解法，但是该方法可以解决此类问题。

1.回溯函数返回值及参数

回溯函数一般没有返回值，即void。需要有集合的边界n、选取几个数k、还需要有一个开始索引startIndex，记录从哪里开始选取数。

2.确定回溯终止条件

声明两个公共成员变量，path为记录单个结果的变量，result记录最终结果，当path的size等于k时，终止，将path变量push进result中。

3.单层回溯逻辑

循环遍历数组，开始为startIndex，结束为n，将值push进path中，然后进行回溯，回溯的最后一个参数为当前元素的后一个，即startIndex等于当前元素的后一个元素所在位置的索引。然后path进行回溯，将当前元素pop出来。

2021/9/24

**题目**

从1到9（包括1和9）取出k个数，使其和相加为n。

**思路**

该题可以使用回溯法，横向遍历1到9，纵向递归。

1.确定回溯函数返回值及参数

回溯函数一般没有返回值，参数是写回溯函数时边写边加的，首先需要n、k，其次需要一个开始索引startIndex

2.终止条件

指定两个公共成员变量，一个存放最终结果，一个存放当前结果。存放当前结果的path数组如果长度达到k并且n的值为0，则将path push进result中。

3.单层回溯逻辑

首先需要从开始索引遍历到9，使n减去当前的i，然后将i push进path中，从i+1开始递归。因为n减去了i，所以要回溯再加上i，push进path中的i要再pop出来。

2021/9/27

**题目**

![image-20210927210853362](C:\Users\admin\AppData\Roaming\Typora\typora-user-images\image-20210927210853362.png)

**思路**

横向遍历数字对应的所有字符，纵向递归。设定两个全局变量：一个为path，记录一种字母组合；一个为result，记录最终结果。当path的size等于给定的数字字符的长度时，将path push进result中，结束。使用index来记录数字字符的索引，将index处的数字字符转化为整形，通过数字找到对应的字符然后遍历字符，将i位置的字符push进path中，然后递归，最后回溯。最后别忘记判断当给定数字字符的大小为0时，直接返回空数组。

2021/9/28

**题目**

![image-20210928213520998](C:\Users\admin\AppData\Roaming\Typora\typora-user-images\image-20210928213520998.png)

**思路**

组合总和可以用回溯法解决。横向遍历给定的int型数组，纵向递归。

可以用target减去数组元素，当target小于0时终止，当target等于0时将满足条件的组合push进result数组中。i从startIndex开始，终止为数组的size，循环。将数组元素push进记录当前组合的数组中，然后令target减去数组元素的值，从i开始递归，因为数组元素可以重复，然后回溯target，之后回溯记录当前数组元素的数组。

2021/9/28

**题目**

![image-20210929111431656](C:\Users\admin\AppData\Roaming\Typora\typora-user-images\image-20210929111431656.png)

**思路**

此题最重要的是去重。组合内可以有元素重复，但是因为组合没有顺序之说，即只要组合内元素相同，则组合相同，因此需要在树的同一层去重。比如[1,1,2],选取1之后同一层则不能再选择1。使用一个存储bool类型元素的数组记录用过的元素。如果used[i-1]==true，则说明该元素在本层没有用过，反之则跳过。重要的一点是需要将数组内的元素进行排序，将相同元素放在一起。
