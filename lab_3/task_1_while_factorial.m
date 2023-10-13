clear
clc
x = 2;
while x <= 20
    if rem(x,2) == 0
        fprintf("the even number is %d \n",x)
    end
    x = x+1;
end

n = input("enter number that get factorial: \n")
frist_value = n
f = n
while n > 1
    n = n-1;
    f = f*n;
end
fprintf('factorial of %d =%d \n',frist_value,f)

