eq2=4
eq1=5
if [ $eq2 -ne 3 -a $eq1 -eq 5 ]
then
echo "AND OPERATION"
fi

if [ $eq2 -ne 3 -o $eq1 -eq 5 ]
then
echo "OR OPERATION"
fi

