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

2021/9/30

**题目**

![image-20210930203144631](C:\Users\admin\AppData\Roaming\Typora\typora-user-images\image-20210930203144631.png)

**思路**

如示例，在第一个a处切割，剩下的在ab中选择；

​				在aa处切割，剩下的在b中选择。

此过程类似组合问题的解决过程。因此可以用回溯。切割线为startIndex，选取的字符串即为[startIndex,i)范围的字符串，判断此字符串是否为回文，如果是，则放入path数组中，否则跳过。判断回文字符串的方法可以用双指针，一个指针指向字符串头，一个指向尾，循环判断，如果其中有不相等的则返回false，否则，返回true。终止条件是当切割线到达字符串的最后，则说明找到符合条件的切割方法了。

2021/10/1

**题目**



![image-20211001220136544](C:\Users\admin\AppData\Roaming\Typora\typora-user-images\image-20211001220136544.png)

**思路**

本题类似回文切割，需要有一个切割线来记录切割位置，同时还需要有一个计数器来记录插入了多少个.。首先判断startIndex到i区间的字符串是否符合要求，如果符合要求则插入点，并且pointiNum+1，然后递归，回溯。终止条件是当pointNum等于3时，这时候说明字符串已经被分为四段了，然后判断第四段是否符合规则，如果符合则push进最终结果集中。字符串不符合规则有以下几种情况：

​			1.以0开头，且不是0.0.0.0

​			2.不是数字字符，即大于9或者小于0

​			3.该字符串大于255

2021/10/2

**题目**

求数组中元素的所有子集，而且不能重复，即只要子集元素相同即为同一个子集。

**思路**

同样是求组合，因此可以使用回溯法，但是本题可以不用终止条件，因为是求所有子集，所以循环中当i>数组大小时，循环已经结束了。

2021/10/3

**题目**

同上题大体类似，只是数组中含有重复元素。

**思路**

思路同上题大体类似，只是需要在同一树层进行去重操作，即判断元素在此之前是否用过，若用过则跳过，否则进行下面的操作。去重操作需要将数组元素进行排序使得相同的元素连续排列，此时可以用判断前后元素是否相同，以及用来记录该元素是否使用过的used数组进行重复判断。若used数组记录的前一个元素的值为false，则说明此元素被使用过，即跳过。

2021/10/4

**题目**

求所给数组的所有递增子序列。

**思路**

同求所有子集不同的是，在求子集的基础上要求子集是递增的，且数组中含有重复元素，因此要在同一树层进行去重操作。

之前的去重操作是需要将数组进行排序之后才能去重，本题如果也这样做，那么本身就是递增的数组，所求的子集也必然是递增的，这样做失去了本题原本的意义。因此可以使用unordered_set记录已经使用过的元素，以此来实现去重操作。

2021/10/5

**题目**

求一个数组所有可能的全排列。

**思路**

排列不同于集合的地方在于排列是有顺序的，即使元素相同，但只要排列顺序不同也是不同的排列。因此可以用一个bool类型的数组来记录哪些元素用过，哪些没用过，直到记录每一个符合条件的数组大小等于nums大小。

2021/10/6

**题目**

求一个数组的所有可能全排列，数组中含有重复元素。

**思路**

本题与上一题的不同之处在于本题的数组中有重复元素，因此在同一层树中需要进行去重操作。从第二个元素起，如果等于前一个元素，且用来记录元素是否用过的数组的前一个元素值为false，此时应该跳过该数，用下一个数。

2021/10/8

**题目**

一些有大小之分的饼干要分给不同胃口的小孩，如果饼干的大小大于等于小孩的胃口，则此饼干可以分给该小孩。尽可能让更多的小孩吃到饼干。

**思路**

该题可以使用贪心算法，通过“饼干的大小满足小孩的胃口”这样的局部最优，以此来达到“让更多的小孩得到饼干”这个全局最优解法。先将记录饼干大小和小孩胃口两个数组排序，然后记录饼干大小数组最后一个元素的索引，从后往前循环遍历小孩胃口，如果索引存在并且饼干的大小可以满足小孩的胃口，则将计数器的值加1，从记录饼干大小数组的倒数第二个开始继续判断，即令索引值减一，以此类推，最后返回记录结果的计数器。

2021/10/14

**题目**

给定一个数组，如果数组连续的数相减的差组成的数组的正负是相间隔的，则说明是摆动序列，第一个差可以是正数或者负数，如果数组有一个或者两个不相等的数，则摆动序列含有元素数量等于数组大小。求摆动序列的大小。

**思路**

![376.摆动序列](https://img-blog.csdnimg.cn/20201124174327597.png)

​	如果一个数在单调的线上则把这个数跳过，不包含头尾两个数，但是要考虑一种情况，如果连续的	两个数相等，差为0的时候，此时也应该算，可以把记录结果的变量的初始值设为1，即默认最后有	一个摆动序列。用一个整形指针记录当前差，另一个整形指针记录前一个差，如果符合摆动序列的条件，则令preDiff等于curDiff，否则什么都不做，最后返回result。

2021/10/18

**题目**

​	给定一个数组，元素有正有负，求最大和的连续子序列，并返回最大和。

**思路**

​	因为数组内元素有正有负，所以最大和必然为正数，所以可以利用这个规律，声明一个记录最终结果的变量，令其初始值为整数里的最小值或者是数组第一个元素的值，声明另一个变量动态记录序列和。如果序列和大于0，此时可以继续往下加数组元素值；否则，应该重置序列第一个元素，令sum等于当前数组元素值。

2021/10/19

**题目**

​	给定一个数组记录每天股票的价格，手中只能有一支股票，即手中的出售后才能买下一个，求最大	利润。

**思路**

​	假定股票在第一天买入，第三天卖出的利润是最大的，则只需求prices[2] - prices[0]。同时上式可	以分解为（prices[2] - prices[1]）+(prices[1]-prices[0])。即只需将数组连续两个元素的差为正数的	相加即可达到最大利润。

2021/10/20

**题目**

​	给定一个数组，里面的元素值表示当前位置可以往后走的步数，判断给定的数组是否可以走到最后	一步，如果可以返回true，否则返回false。

**思路**

​	声明一个变量记录当前位置可以往后走的最大步数，每次判断此值是否大于等于数组最后元素下标值，如果是返回true，如果循环完毕没有返回值，则返回false。记录最大步数的变量每次要加当前下标值，因为已经在此位置。

2021/10/21

**题目**

​	同昨天的题，但是一定可达，同时在使用最少步数的前提下走到数组末尾。

**思路**

​	在元素指定区间内寻找最大可走步数，最终达到用最少的步数走到最后。

​	声明一个变量记录当前元素指定区间的最大元素，另一个变量记录走到最后的步数，还有一个变量记录边界。循环遍历数组到倒数第二个元素，因为一定可达，所以最后到达的位置一定是在最后一个元素处或者其后面。如果指针到达边界，则步数就要加1，并且更新边界值。最后返回走的步数。

2021/10/22

**题目**

​	给定一个数组和一个k值，将索引为i的数变为相反数，i可以多次选择，保证选择数为k，然后求变换之后数组的最大和。

**思路**

​	首先可以将数组按照绝对值大小从大到小排序，然后遍历排序之后的数组，如果数组元素小于0并且k大于0，则将数组元素变为其相反值，同时k减1。循环之后如果k为奇数则将数组最后一个元素变为相反数，如果为偶数则说明剩下的正数是从正数变为负数再变为正数，因此可以忽略不计。最后求和。

2021/10/24

**题目**

​	给定一个记录可以加多少油量的数组gas和一个耗费多少油量的数组cost，判断是否有一个出发点可以使得汽车从此出发点出发可以回到出发点。

**思路**

​	暴力解法：第一重循环遍历数组，寻找可以到达的出发点i

​	第二重循环使用while循环遍历，判断i索引处出发是否可以再回到出发点。

​	二重循环完成后如果剩余油量大于等于0并且二重循环停留的索引值等于i值，则返回此i

​	如果一重循环结束之后仍然没有返回值，此时则返回-1。

2021/10/25

**题目**

​	给定一个记录面币大小的数组，一杯柠檬水的价格是5元，判断一直到数组最后一个元素是否能够成功找零，面币大小只有5、10、20三种。

**思路**

​	因为只有三种面币大小，所以可以模拟过程。声明三个变量分别记录收到的5、10、20的数量，当收到的是5元时，record5加一；当收到的是10元时，判断是否有大于等于1张的5元纸币，如果有则record5--，record10++，否则返回false；当收到的是20元时，优先判断是否有大于0张的5元和10元纸币（因为10元纸币只能找给收到的纸币大小是20元的情况），如果有则record5--，record10--，record20++，否则判断是否有大于等于三张的5元纸币，如果有则record5-3，否则返回false。

2021/10/26

**题目**

​	给定一个记录i位置的人身高和前面有多少人大于等于其身高的数组，将其进行正确排序，并且放入数组中。

**思路**

​	首先将数组按照身高从大到小排序，保证每个人前面的人的身高均大于等于其身高值，如果两个人身高值相同则按照h值从小到大排序。然后将i位置的元素插入到h的地方。

2021/10/27

**题目**

​	给定一个二维数组，每个元素记录的是气球起始到终止横坐标，箭从横坐标某个点出发，垂直射向气球，如果箭出发的横坐标在气球的起始终止坐标范围内（包含边界），则箭可以射中气球，求射中所有气球需要的最小箭数。

**思路**

​	首先可以将数组按照points[i] [0]进行排序，然后从第一个元素的下标开始循环，如果当前元素的左边界大于前一个元素的右边界说明没有重叠的区间，所以箭数需要加1，如果小于等于的时候，比较当前元素和前一个元素的右边界哪个小，更新当前元素右边界。

2021/10/28

**题目**

​	给定一个数组，去除含有重复区间的元素，注：去除最少元素。

**思路**

​	按照元素的右区间从小到大排序，右区间越小说明重叠区间越少，可以计算不重叠区间的元素的数量，然后用总数减去此数。

2021/10/29

**题目**

​	给定一个字符串，求划分“尽量多”的片段，将每个片段含有的字符数量记录下来保存到数组中，返回此数组。注：每个字母最多出现在一个片段中

**思路**

​	声明一个数组记录每个字母的最远下标值，声明一个记录结果的数组、两个整型变量分别记录片段左右边界。循环遍历字符串，比较右边界的大小，每次取大的右边界，如果右边界的值到达了字母的最远下标值，则将片段含有字母数量push进结果数组中，更新左边界的值为当前右边界值加1。

2021/10/30

**题目**

​	将有重复区间的数组进行合并，返回合并之后的结果

**思路**

​	将二维数组按照每个元素的左区间升序排列，声明一个bool变量记录最后一个元素是否被放入最后结果中，从第二个元素的下标开始循环，声明两个变量记录前一个元素的左、右区间，如果循环值小于数组大小并且当前元素的左区间小于等于前一个元素的右区间值，更改右区间值为当前元素右区间和前一个元素右区间值较大的一个，循环值向后移，并且如果循环值移动到了最后，令flag等于true。将当前的左右区间变量放入记录最终结果的数组中。循环结束后判断最后一个元素如果没有被放入结果，则放入。

2021/10/31

**题目**

​	给定一个数字，返回小于等于此数字的数，要求返回数的数字排列是单调递增的

**思路**

​	将数字变为字符串从后向前遍历，如果当前数小于前一个数，则用声明的全局变量记录下来此索引值，并将前一个数的大小减1，依此类推。从全局变量开始循环，直到字符串大小，将对应索引值变为9。注：全局变量的初始值一定要是字符串的大小，因为如果给定的数是恰好符合条件的话，不需要变，直接返回即可。

2021/11/1

**题目**

​	给定一个数组表示每天股票的价格，尝试找到最大的利润，注意：每次交易都有相应的手续费，一次交易是买入卖出的过程。

**思路**

​	情况1：当前股票价格相对较低，买入

​	情况2：当前股票买入价格太高，卖出收获不到利润，保持原样

​	情况3：当前股票价格大于成本，模拟收获利润的过程，但是这不一定是最后一次卖出，所以记录利润之后同时要将记录股票价格最小值的变量减去交易费，以此避免多减一次交易费。

2021/11/2

**动态规划五部曲**

​	1.确定dp数组以及其下标的意义

​	2.确定递推公式

​	3.dp数组如何初始化

​	4.确定遍历顺序

​	5.举例推导dp数组

**以“斐波那契数”为题举例**

​	1.确定dp数组以及其下标的意义：

​		dp[i]定义：第i个数的斐波那契值是dp[i]

​	2.确定递推公式

​		dp[i] = dp[i-1] + dp[i-2]

​	3.dp数组初始化

​		dp[0] = 0; dp[1] = 1;

​	4.确定遍历顺序

​		因为dp[i] = dp[i-1] + dp[i-2] ,所以数组是从前向后遍历的

​	5.举例推导dp数组

​		举例当n=10时，应该的结果是多少，看是否和打印出来的数一致。

2021/11/3

**题目**

​	给定一个台阶数，当台阶数为1的时候可以走一步；当台阶数为2的时候可以选择一次走一层，或者直接走两层。求给定台阶数可以有多少种方法走到。

**思路**

​	由题目推导出求当前台阶的走法可以是前面两个的和，dp[i]表示走i层楼梯有多少种方法。如果n=0直接返回n即可，从n=1开始，将基层楼梯对应有多少种走法记录在数组中，初始化n=1和2的时候的数值，从3开始循环求走法，最后返回。

2021/11/4

**题目**

​	....（没有看懂题目）给定一个数组记录每层台阶的体力耗费值，我的理解是走到当前台阶需要的耗费值，可以选择走一步也可以选择走两步，哪种选择体力耗费值最小。

**思路**

​	用一个数组来记录走到每层台阶需要的耗费值累加值，每次从前两个台阶选择最小耗费值累加，最后返回数组倒数两个元素的较小值。

2021/11/5

**题目**

​	给定一个m×n的格子，从（0，0）点出发到（m，n）判断有多少条路径可以到达。

**思路**

​	本体可以使用动态规划找规律，因为只能向右和向下走，因此到达（i，j）的路径是到达（i-1，j）和（i，j-1）的值，到达（i，0）和（0，j）的路径都是只有一条，因此可以进行初始化，循环求出最后一个数组元素的值即为最后的结果。

2021/11/6

**题目**

​	同上一题相同，不过添加路障，用数组记录没有路障的为1，有路障的为0，计算总共有多少条路可以从起点到达终点。

**思路**

​	同上一题一样，只需要多做一步跳过路障即可。首先初始化的时候将可走的格子的值初始化为1，然后循环计算的时候如果当前格子为路障则continue，否则当前格子的值为上面和左面格子的值相加。

2021/11/7

**题目**

​	给定一个数，将此数拆成至少两个数相加等于此数，然后将拆分的数相乘，求乘积最大值

**思路**

​	1.dp[i]的含义

​		表示i拆分之后乘积的最大值。

​	2.初始化

​		从2开始初始化，因为1和0无法拆分，即使拆分也没有意义，所以dp[2] = 1;

​	3.循环

​		i可以拆分成i-j和j，也可以拆分成dp[i-j]和j，dp[i-j]的含义是i-j的乘积最大值。前者是两个数的积		后者是三者及其以上数的乘积。同时每次要比较dp[i]的大小，更新dp[i]的值。

2021/11/8

**题目**

​	给定节点数，求可以组成多少个不同的二叉树

**思路**

​	1.确定dp[i]的definition

​		有i个节点时可以组成二叉树的数量

​	2.初始化

​		dp[0] = 1;表示有0ge节点时，可以组成一个空的二叉树

​	3.循环规律

​		dp[i]+=dp[j-1]*dp[i-j];

2021/11/9

**题目**

​	给定每个物品的重量和价值以及书包的最大承重，求可以放的物品的最大价值总和

**思路**

​	1.确定dp[i] [j]的含义

​		表示放下标为i的物品在容量为j的书包中可以达到的最大价值总和。

​	2.初始化

​		当书包容量为0的时候，任何物品都放不了，此时dp[i] [0]均为0，放下标为0的物品时有两种情况：  

​			1）书包容量小于下标为0的物品的重量，此时价值应为0；

​			2）书包容量大于等于下标为0的物品的重量，此时价值应为下标为0的物品的价值。

​		其余的最好初始化为0，因为随着循环更新最大值，总会被覆盖，因此赋什么值都可以，但是赋0会		更加方便操作，只需在数组初始化的时候一块赋值，然后更新下标为0的物品放进去的数值即可。

​	3.循环赋值

​		当前物品的重量如果大于书包容量的话，价值还是等于前一个物品的价值最大值

​		当前物品的重量如果小于等于书包容量的话，价值应该是之前的价值总和加上当前物品的价值和之		前的价值总和作比较的较大值。

​		遍历顺序可以是先遍历物品，再遍历书包容量。

2021/11/10

**题目**

​	给定表示重量的数组以及表示物品价值的数组，书包的容量，求可以放入物品的最大价值总和。

**思路**

​	1.确定dp[j]的含义

​		dp[j]表示书包容量为j的时候可以放的物品最大价值总和。

​	2.确定递推公式

​		递推公式是比较放i物品和不放i物品哪个价值更大，即dp[j] = max(dp[j],dp[j-weight[i]]+value[i])

​	3.初始化

​		当书包容量为0的时候可以放的物品是0，因此价值也是0，因为是选取较大值将之前的值覆盖，而		价值都大于等于0，所以可以将数组元素值全都初始化为0。

​	4.遍历顺序

​		先遍历物品再遍历书包容量，物品正向遍历，书包容量反向遍历，因为数组后面元素是基于前面元	素的值的，如果从头开始遍历，那么后面的值就会一直加前面元素的值，最后导致结果错误。

2021/11/11

**题目**

​	给定一个数组，判断是否可以分成两个元素和相等的数组。

**思路**

​	类比背包问题，即将元素放入数组中，可以达到目标值，而目标值是数组元素总和的一半。

​	1.确定dp[i]的含义

​		即目标值为i的数组可以放的元素总和

​	2.递推规则

​		放入当前元素和不放入哪个和更大

​	3.初始化

​		因为数组元素都是整数，因此初始化为0

​	4.遍历顺序

​		因为每次后面的值是基于前面的值的，所以遍历数组是正序遍历，遍历元素值是倒序遍历。

​	本题中重量和价值均是nums[i]

2021/11/12

**题目**

​	给定一个数组，数组元素表示石头的重量，如果两块石头重量相同则相撞后两者都消失，如果一大一小则相撞后剩下的石头的重量为原来的重量减去小石头的重量。求最后数组剩下的石头的最小重量。

**思路**

​	石头重量最小可以转化为将数组分为两部分，两部分分别占数组元素总和的一半，即使数组元素总和是奇数，那两者相减得到的最终值也是最小值。所以此题可以转化为01背包问题。容量为j的书包可以盛放的石头重量，价值和重量均为stones[i]。因为sum/2是向下取整的，因此另一半的值一定大于等于此值，因此最后用另一半的值做被减数。

2021/11/13

**题目**

​	给定一个数组，让其所有的元素无论加还是减，最终的和达到给定的目标值

**思路**

​	如果用加法总和是x，那么用减法的总和是数组元素总和sum-x，现在使得加法和减去减法和等于目标值，即x-（sum-x）=target，所以可以求出加法和为（sum+target）/2，所以此问题转变成为了有多少种方法可以使得重量为（sum+target）/2的背包装满，是01背包问题的原因是数组元素只能用一次，并且此题还是组合问题，所以递推公式应该是方法值的累加。

2021/11/14

**题目**

​	给定一个元素类型是字符串的数组，字符串时二进制字符串，由0和1组成，给定m和n，分别表示可以使用的0和1的最大数量，求最长子集的长度。

**思路**	

​	同一个0 1只能使用一次，因此这是01背包问题，同时这个背包问题有两个维度，即向容量为m的背包放0和向容量为n的背包放1，怎样可以放最多，数量是多少。

2021/11/15

**题目**

​	给定代表物品重量和价值的数组，放入可以盛放一定重量物品的数组中，求放入物品的最大价值总和。注：物品可以无限使用。

**思路**

​	同01背包不同的是，物品可以无限使用，所以内层遍历重量的时候要从小到大遍历。

2021/11/16

**题目**

​	给定表示硬币大小的数组，求使用此数组中的硬币组成指定钱数可以有多少种不同的组合。假设一个硬币可以无限取

**思路**

​	因为硬币数量可以无限取，所以这是完全背包问题，且是装满amount大小的背包有多少种不同的方法。因此需要累加。遍历顺序为先遍历硬币再遍历价值，价值是从小到大遍历，因为一个硬币可以无限用。

2021/11/17

**题目**

​	给定表示硬币大小的数组，从数组中选择硬币组成target数值的组合。一个硬币可以无限使用，并且组合顺序不同算不同的组合，求组合数。

**思路**

​	因为硬币可以无限使用，所以是完全背包问题。因为有关于顺序，所以是排列问题。排列的话需要先遍历价值，再遍历物品，因为[1,3]和[3,1]是两个不同的组合，如果先遍历物品，再遍历价值的话，不会出现后者。

2021/11/18

**题目**

​	给定一个数组表示硬币的金额，硬币可以无限使用，求组成一定金额使用的最小硬币数，如果无法组成则返回-1.

**思路**

​	此题的dp[j]表示组成j金额需要使用的最小硬币数量，因为是求最小值，因此初始化的时候需要赋予最大值避免被覆盖。组成0金额需要的最小硬币数是0，无关顺序，因此先遍历物品还是先遍历背包都可以，遍历背包要从小到大遍历，因为是完全背包问题。

2021/11/19

**题目**

​	给定一个数，找到最少个平方数相加等于此数，平方数是指可以开方成整数的数。求有多少个平方数，返回此值。

**思路**

​	首先需要记录小于等于n区间内所有的平方数，用数组记录下来。因为无关顺序，所以是组合问题，同时平方数可以无限使用，因此是完全背包问题。注：记录平方数，区间要取到等于n，因为如果给定n=1时，有一个平方数可以组成1，即本身。

2021/11/20

**题目**

​	给定一个字符串和和字符串类型的字典，判断字典中的字符串是否可以组成字符串。字典中的字符串可以无限使用。

**思路**

​	字典中的字符串是物品，字符串是背包，判断物品是否可以装满背包。外层遍历背包容量，最大到字符串的长度，内层遍历物品，物品最大到背包容量。截取（j，j-i）长度的s字符串判断是否在字典中出现并且dp[j]是否为true，如果是，则dp[i]同样为true。

2021/11/21

**题目**

​	给定数组表示房子内有的钱的数量，进入相邻房子会触发报警系统，求可以偷到的最大钱数。

**思路**

​	01背包问题。dp[i]表示进或不进入i房子，可以偷到的最大钱数。如果进入i房子，则此时可以偷到的钱数为dp[i-2]+nums[i]；如果不进入，此时可以偷到的钱数为dp[i-1]。比较两个数哪个大即是哪个。初始化：进入0号房子获得的钱数为nums[0],进入1号房子获得的钱数为前一个房子的钱数和当前房子钱数的较大值。

2021/11/22

**题目**

​	同上题，不过房子成环形连接，即第一个房子和最后一个房子不能都选择。

**思路**

​	考虑三种情况：首尾房子都不选择；选择首，不选择尾；选择尾，不选择首。因为第一种情况后面都包括了，因此只考虑后面两种情况即可。当只有两个元素时，返回nums[start]即可。

2021/11/23

**题目**

​	小偷发现房子只有一个入口，并且房子是呈树形排列的，是二叉树，如果连续访问直接相连的两个房子则会触发报警系统，求可以获得最大钱数。

**思路**

​	声明一个数组长度为2，下标为0时表示偷当前节点的房子可以获得的最大钱数；下标为1表示不偷当前节点的房子可以获得的最大钱数。返回两者之间的最大值。同时递归左右孩子节点。如果偷当前节点则是当前节点房子含有的钱加上不偷当前节点的左右孩子节点可以获得的最大钱数相加。如果不偷当前节点则是偷或者不偷左孩子节点的较大值加上偷或者不偷右孩子节点的较大值。

2021/11/24

**题目**

​	给定数组表示第i天某支股票的价格，选择一天买入，然后选择一天卖出，求可以获得的最大利润。注：买入的价格要小于卖出的价格，如果没有利润返回0。

**思路**

​	声明一个变量记录买入股票最小值，另一个变量记录结果，循环数组更新股票最小值以及结果值，返回结果。

2021/11/25

**题目**

​	给定数组，求数组最长递增子序列。最长递增子序列的相对顺序是不变的。

**思路**

​	声明dp[i]数组表示i长度的数组的最长子序列的长度。双重循环，第一层循环表示数组中有多少元素，第二层循环表示递增子序列有多长，内层循环求给定长度数组的最长递增子序列，外层循环求所有数组长度的最长递增子序列。注：当数组长度为1时，最长递增子序列是其本身。

2021/11/26

**题目**

​	给定一个数组，求此数组的最长连续递增子序列，返回最长递增子序列的长度。

**思路**

​	声明数组dp[i]记录i个元素的最长递增子序列的长度，初始值为1，返回dp数组的最大值。求dp数组时，更新条件是给定数组的前一个元素小于后一个元素的值。

2021/11.27

**题目**

​	给定两个数组，求两个数组重复的最长子序列的长度。

**思路**

​	dp[i] [j]表示下标为i-1的数组A和下标为j-1的数组B的最长子序列的长度值。从i和j为1时开始循环。

2021/11/28

**题目**

​	给定两个字符串，求最长公共子序列的长度。最长公共子序列的相对顺序要与两个字符串相同。

**思路**

​	同求数字的最长公共子序列的长度，不同的是，当前两个字符串的字符不相同时，dp[i] [j] = 

​	max(dp[i-1] [j],dp[i] [j-1])。
