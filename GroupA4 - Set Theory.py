list_a=[1,2,3,4,5,6]
list_b=[10,9,8,7,6,5,4]

def intersection(list_a, list_b):
    list_c=[item for item in list_a
        if item in list_b]
    return list_c 
        
def union(list_a, list_b):
    list_c=list_a
    for item in list_b:
        if item not in list_c:
            list_c.append(item)
        return list_c
        
def difference(list_b, list_a):
    list_c=[item for item in list_a
        if item not in list_b]
    return list_c
    
flag=1 
while flag==1:
    print("\t--------MENU---------")
    print("\t--List operations--")
    print("\n1.Add elements \n2.Delete elements \n3.Display sets \n4.Intersection \n5.Union \n6.Difference \n7.Exit ")
    choice=int(input(" Enter your choice: "))
    
    if choice==1:
        list_a.append(int(input(" Enter elements to be added in list A: ")))
        list_b.append(int(input(" Enter elements to be added in list B: ")))
        print(" Elements are added! ")
    
    elif choice==2:
        list_a.remove(int(input(" Enter element to be removed from list A: ")))
        list_b.remove(int(input(" Enter element to be removed from list B: ")))
        print(" Elements are removed! ")
    
    elif choice==3:
        print(list_a,list_b)
        
    elif choice==4:
        print(intersection(list_a, list_b))
    
    elif choice==5:
        print(union(list_a, list_b))
        
    elif choice==6:
        print(difference(list_a, list_b))

    elif choice==7:
        quit()



