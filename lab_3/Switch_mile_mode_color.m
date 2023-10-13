clear
clc

transportation = input("Enter mode that you want to know the cost for: ","s")
num_mile = input("enter number of mile: ")
switch transportation
    case 'car'
        fprintf("the cost for car is %d per %d mile \n",2000*num_mile,num_mile)

    case 'train'
        fprintf("the cost for train is %d per %d mile \n",3000*num_mile,num_mile)
    case 'bus'
        fprintf("the cost for bus is %d per %d mile \n",4000*num_mile,num_mile)
    otherwise
        disp(["enter right mode from [car , train , bus]"])
end
color_iterator = 1
while color_iterator <=5

    color_code = input("Enter color code: ","s")

    switch color_code
        case '#050505'
            fprintf("color code number %d is black \n",color_iterator)
        case 'F5Be1d'
            fprintf("color code number %d is red \n",color_iterator)
        case 'c63c24'
            fprintf("color code number %d is blue \n",color_iterator)
        case "#4DBEEE"	
            fprintf("color code number %d is sky \n",color_iterator)
        case '77AC30'
            fprintf("color code number %d is green \n",color_iterator)
        otherwise
            disp(["enter right colors [#050505 F5Be1d c63c24 #4DBEEE 77AC30]"])
    color_iterator = color_iterator+1
    end
end