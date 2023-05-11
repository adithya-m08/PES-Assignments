public class MyNum
{
private int val;
public MyNum(int val)
{
this.val = val;
}
public int findSum() // wrapper for a recursive method
{
return findSumRecursive(val);
}
private int findSumRecursive(int val)
{
if(val == 0)
// escape hatch or base case
{
return 0;
}
else
{
// recursive step
return val % 10 + findSumRecursive(val / 10);
}
}
}