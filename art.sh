echo "Enter 1st Number: "
read one
echo "Enter 2nd Number: "
read two

three=`expr $one + $two`
echo $three
echo "Addition:" `expr $one + $two`
echo "Subraction:" `expr $one - $two`
echo "Multiplication:" `expr $one \* $two`
echo "Division:" `expr $one / $two`

