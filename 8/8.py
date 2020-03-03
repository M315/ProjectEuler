def main():

    #read the string from  file
    f=open("serie1.txt", "r")
    if f.mode == "r":
        content = f.read()
    
    #separate the string into one digit-number
    prod = 1
    for i in range(0,13):
        prod = prod*int(content[i])
    
    max_prod = prod

    for i in range(13,987):
        prod = 1
        for j in range(0,13):
            prod = prod*int(content[i+j])
        if prod > max_prod:
            max_prod = prod
    
    print(max_prod)

if __name__=="__main__":
    main()