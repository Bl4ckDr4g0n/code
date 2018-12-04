#!/usr/bin/python3

def get_earliest(date1, date2):
    a = date1.split("/");
    b = date2.split("/");
    if (a[2] < b[2]):
        return date1
    elif (b[2] < a[2]):
        return date2
    else:
        if (a[0] < b[0]):
            return date1
        elif (b[0] < a[0]):
            return date2
        else:
            if (a[1] < b[1]):
                return date1
            elif (b[1] < a[1]):
                return date2
            else:
                return date1

def get_earliest_wrapper(*args):
    res = args[0]
    for arg in args:
        res = get_earliest(res.join("/"), arg)
    return res.join("/")

date1 = input()
date2 = input()
date3 = input()
date4 = input()
date5 = input()


print(get_earliest_wrapper(date1, date2, date3, date4, date5))
