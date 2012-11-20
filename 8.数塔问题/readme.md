<div id="article_content" class="article_content">
<p>&nbsp;</p>
<div class="panel_title">Problem Description(HDUOJ2084)</div>
<div class="panel_content">在讲述DP算法的时候，一个经典的例子就是数塔问题，它是这样描述的：<br><br>有如下所示的数塔，要求从顶层走到底层，若每一步只能走到相邻的结点，则经过的结点的数字之和最大是多少？<br><img src="http://acm.hdu.edu.cn/data/images/C44-1004-1.bmp" alt=""><br>已经告诉你了，这是个DP的题目，你能AC吗?</div>
<div class="panel_bottom">&nbsp;</div>
<p>&nbsp;</p>
<div class="panel_title">Input</div>
<div class="panel_content">输入数据首先包括一个整数C,表示测试实例的个数，每个测试实例的第一行是一个整数N(1 &lt;= N &lt;= 100)，表示数塔的高度，接下来用N行数字表示数塔，其中第i行有个i个整数，且所有的整数均在区间[0,99]内。</div>
<div class="panel_bottom">&nbsp;</div>
<p>&nbsp;</p>
<div class="panel_title">Output</div>
<div class="panel_content">对于每个测试实例，输出可能得到的最大和，每个实例的输出占一行。</div>
<div class="panel_bottom">&nbsp;</div>
<p>&nbsp;</p>
<div class="panel_title">Sample Input</div>
<div class="panel_content">
<pre><div>1
5
7
3 8
8 1 0 
2 7 4 4
4 5 2 6 5</div></pre>
</div>
<div class="panel_bottom">&nbsp;</div>
<p>&nbsp;</p>
<div class="panel_title">Sample Output</div>
<div class="panel_content">
<pre><div>30</div></pre>
</div>
<div class="panel_bottom">&nbsp;</div>

</div>