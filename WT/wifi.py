 #bank management system using python
import os
import time
from random import *
import smtplib
from tkinter import *
server=smtplib.SMTP('smtp.gmail.com',587)
server.starttls()
server.login('pythondemo3@gmail.com','ylplaxdjwpmplljf')

print("\n**************BANK MANAGEMENT SYSTEM******************\n")
print("\t\tby: ASHLESHA ,DHRUVA ,ARUN")
pas={}
k=0
A_C_DATABASE={}
p=[]
q=[]
cvv=[]
def account():
    print("welcome to \"ADA BANK\"\n") 
    account.ADN=input("enter your aadhar number : ")
    
    if(len(account.ADN)==12):
       
        account.name=input("enter your name : ")
       
        account.address=input("enter your address : ")
    
        account.email=input("enter your email id : ")
        
        account.cnum=input("enter your number : ")
       
        if(len(account.cnum)!=10):
            print("please rewrite your number and enter details from begining ")
            account()   #recursion
        else:
            def acnum():
              p.append(randint(10000,99999))
              for i in p:
                if(p.count(i)>1):
                    p.remove(i)
                    return(acnum())
                else:
                    f=open(str(p[len(p)-1]),"x")
                    f1=open("text_f1.txt","a")
                    f1.writelines(str(p[len(p)-1])+".txt\n")
                    
                    print("your account number is ",p[len(p)-1])
                    break;  
                 
            acnum()
            print("$$$$$$$$$$$$$$$$$$ your account has been created $$$$$$$$$$$$$$$$$")

            amt=int(input("enter the initial amount : "))
            account.amt1=str(amt)
            ###########################################################
            f=open(str(p[len(p)-1])+".txt","w")
            f.writelines(account.name+"\n") 
            f.writelines(account.address+"\n") 
            f.writelines(account.ADN+"\n") 
            f.writelines(account.cnum+"\n") 
            f.writelines(account.amt1+"\n") 
            account.amt1=amt
            print("your deposit of rupees ",amt," is successful: ") 
            server.sendmail('pythondemo3@gmail.com',account.email,'YOUR ACCOUNT HAS BEEN CREATED in \"ADA BANK\"\nAccount no '+str(p[len(p)-1])+'\t\tIFSC CODE= ADA1289675\nAccount holders name  '+account.name+'\nthe total amount in your account is'+str(account.amt1)) 
    
            print("an mail has been sent to ur registered mail\n") 

            print("do u need atm card type S/N  ")
            z=input()
            if(z=="S"):
                def atm():
                    q.append(randint(100000,999999))
                    for i in q:
                        if(q.count(i)>1):
                            q.remove(i)
                            return(atm())
                        else:
                            print("atm card generated visit ATM to set green pin") 
                            cvv.append(randint(100,999))
                            f.writelines(str(q[len(q)-1])+"\n")
                            f.writelines(str(cvv[len(cvv)-1])+"\n")
                            f.writelines(account.email+"\n")
                             
                            server.sendmail('pythondemo3@gmail.com',account.email,'ATM NUMBER '+str(q[len(q)-1])+'\ncvv '+str(cvv[len(cvv)-1])+'\n\nDONOT SHARE YOUR CVV OR ATM PIN WITH ANYONE')
                            print("details about atm sent through mail..")
                            break
                atm()        
                            
    else:
        print("invalid aadhar number RE_ENTER")
        account()  
    print(q,cvv)       
    #############################################
    f=open("C:\\Users\\Ashlesha\\text_f1.txt","r")
    print(f.read())
    #############################################

     
    choose()
def UPI_c():
 
  def regis(): 
   val2=input("enter your registered email id ")
   val3=input("enter adhar number ")
   f1=open("text_f1.txt","r")
   r=f1.read()
   r1=r.split("\n")
   for i in r1:
    f5=open(i+".txt","r")
    r2=f5.read()
    r3=r2.split("\n")
    if(r3[7]==val2 and r3[2]==val3):
    
     dfg=str(randint(1000,9999))
     print("an otp has been sent to your mail. ")
     server.sendmail('pythondemo3@gmail.com',val2,dfg)
     otp=input("enter the otp ")
     if(otp!=dfg):
        print("!!! wrong otp  !!!  retry") 
        regis()
     else:
      print("create a passowrd\n")
      UPI_c.passw=input()
      UPI_c.passw1=input("re-enter the password ")
      if(UPI_c.passw==UPI_c.passw1):
        f=open(i+".txt","a")  
        f.writelines(UPI_c.passw+"\n")
        print("password set successful!! enter your name and password to login!!\n")
        pas[val2]=[UPI_c.passw]
        UPI()
      else:
        print("password do not match RETRY!!")
        UPI_c() 
    
   print("\nENTERED E MAIL OR ADHAR NUMBER DONOT MATCH !!RETRY")
  regis()      
   
  choose()        
def UPI():   
       l=0;c=0;v=0     
       UPI.usr_id=input("ENTER YOUR email AS USER ID : ")
       PAS_1=input("PASSWORD : ")
       print("press enter to login : ")
       input()
       f1=open("text_f1.txt","r")
       r=f1.read()
       r1=r.split("\n")
       print(r1)
       for i in r1:
         print(i)
         f=open(i+"txt","r")
         r2=f.read()
         r3=r2.split("\n")
         print(r3) 
         if(r3[7]==UPI.usr_id and r3[8]==PAS_1):
           #*************************************************88
            
            print("logged in \n")
            def new():
             print("enter\n1.create upi id and set upi pin\n2.transfer amount\n3.withdraw money\n4.my balence\n5.exit")
             choise=int(input())
             if(choise==1):
    
                print("enter your atm number and cvv\n")
                val1=(input())
                val2=(input())

                ch=input("have u set ur green pin S/N ")
                if(ch=="S"):
                 
                 if((r3[5]==val1)and(r3[6]==val2)):
                    atm_p=input("enter your atm pin ")
                    if(atm_p==r3[9]):#add pin in dictionary first
                        def fun():
                         print("create new upi id and pin ")
                         UPI.upi_id=input()
                         UPI.upipin=input()
                         upi1=input("re_enter pin ")
                         if(UPI.upipin==upi1):
                            f=open(i+".txt","a")
                            f.write(UPI.upipin)
                            
                            server.sendmail('pythondemo3@gmail.com',r3[7],'your upi pin set successfully \n')
                            print('$$ successful $$')
                            
                            new()
                            #10 index in dict
                            
                         else:  fun()  
                        fun()#write if ac numb if wrong
                 else:
                    print("invalid details  RE_ENTER")
                    UPI()
                else:
                    gp()    
                           
             elif choise==2 :
               def tr(): 
                ac_n=input("write account number to transfer and ifsc code,and price \n")
                ifsc=input()
                price=int(input("enter amount needed to send "))
                if(ifsc=='ADA1289675'):
                    
                    def ppn():      
                     pin=input("enter UPI pin\n")    
                     if(pin==r3[10]):
                
                        if(int(r3[4]>price)):
                         f=open(i+".txt","r")
                         r=f.read()
                         r2=r.split("\n")
                         f=open(i+".txt","w") 
                         k=0
                         f.write(r2[k]+"\n")
                         k+=1
                         while k<=3:
                            f.writelines(r3[k]+"\n")
                            k+=1
                         f.writelines(str(int(r3[4])-price))
                         k+=1 
                         while k<=10: 
                            f.writelines(r3[k]+"\n")
                            k+=1
                         f1=open("text_f1.txt","r")
                         r4=f1.read()
                         r5=r4.split("\n")
                         for i in r5:
                            if(ac_n==i):         
                              f=open(ac_n+".txt","r")
                              r=f.read()
                              r2=r.split("\n")
                              f=open(ac_n+".txt","w") 
                              k=0
                              f.write(r2[k]+"\n")
                              k+=1
                              while k<=3:
                               f.writelines(r3[k]+"\n")
                               k+=1
                              f.writelines(str(int(r3[4])+price)) 
                              k+=1
                              while k<=10: 
                               f.writelines(r3[k]+"\n")
                               k+=1
                              


                            #add herererer
                         # A_C_DATABASE[j][4]=A_C_DATABASE[j][4]-price
                         # A_C_DATABASE[ac_n][4]=A_C_DATABASE[ac_n][4]+price\
                         f=open(i+".txt","r")
                         r=f.read()
                         r2=r.split()
                         print(" success ful ")
                         server.sendmail('pythondemo3@gmail.com',r3[7],str(price)+" rupees has been debited from your account\n your xurrent bal "+str(r3[4]))
                         server.sendmail('pythondemo3@gmail.com',r2[7],str(price)+" rupees has been cridited to your account\n your xurrent bal "+str(r2[4]))
                         new()
                     else:
                        print("wrong pin")
                        l+=1
                        if l==3:
                            new()
                        ppn()
                else:
                    print("invalid. retry !!! ")
                    v+=1
                    if v==3:
                        new()
                    tr()
               tr() 
               
             elif choise==3 :
                 price=int(input("enter amount needed to withdraw "))
                 pin=input("enter UPI pin\n")
                 
                 if(pin==r3[10]):
                        if(int(r3[4])>price):
                         f=open(i+".txt","w")
                         f.write(r3[0]+"\n")   
                         k=1
                         f=open(i+".txt","a")
                         while k<=3:
                            f.writelines(r[k]+"\n")
                            k+=1
                         
                         f.writelines(str(int(r3[4])-price))
                         k+=1
                         while k<=10:
                            f.writelines(r3[k])   
                         print(" success ful ")
                         server.sendmail('pythondemo3@gmail.com',r3[7],str(price)+" rupees has been debited from your account\n your xurrent bal "+str(r3[4]))
                         new()
                        else:
                            print("insufficient amount retry ")
                            choose()
                            c+=1
                            if c==3:
                                new()
                 else:
                    print("invalid pin")   
                    UPI()
                    
             elif(choise==4):
                root=Tk()
                root.geometry("300x300")
                def bal():
               
                 def balence():
                    str1=Text.get()
                    if(str1==r3[10]):
                        #create new window
                        wind=Tk()
                        wind.geometry("300x300")
                        wind.config(bg="cyan")
                        M=Label(wind,text="your account balence is:  "+r3[4]+" rupees",fg="red")
                        M.pack()
                        wind.mainloop()

                    else:
                        Text.delete(0,END) 
                        Text.insert(0,"wrong pin")
                        time.sleep(2)
                        
                        

                 MyL=Label(root,text="Enter your UPI PIN")
                 MyL.pack()
                 Text=Entry(root,width="20")
                 Text.pack()
                 B=Button(root,text="click",command=balence) 
                 B.pack()
                 root.mainloop()
                bal()       
             elif(choise==5):
                choose()        
            new()  
       print(" wrong id or adhar")    
       UPI() 
       choose()           
def gp():
    num=input("enter your account number ")
    f1=open("text_f1.txt","r")
    r=f1.read()
    r2=r.split("\n")
    for j in r2:
        if(str(j)==num):
            f=open(j+".txt","r")
            r4=f.read()
            r5=r4.split("\n")
        
            va=str(randint(1000,9999))
            server.sendmail('pythondemo3@gmail.com',r5[7],"your high security OTP IS  "+va)
            print("enter the otp sent to your mail ")
            otp=input()
            if(va==otp):
                gp.green=input("enter your new 4 digit atm pin ")
                
                f=open(num+".txt","a")
                f.writelines(gp.green+"\n")
                
               
                print("green pin set succesffully$$")

                choose()
            else:
                print("wrong otp RETRY ")
                gp()
    print("entered account number does not exist in ADA bank ")  
    gp() 
           
         
    choose()        
def n_ac():
    pas=input("enter bank password ")
    if pas=="ADA@20203$" :
        f1=open("text_f1.txt","r")
        r=f1.read()
        r2=r.split("\n")
        print("\nbank has ",len(r2)-1," accounts\n")
        time.sleep(2)
    else:
        print("wrong password!!!")
    choose()

def close_ac():
    val=input("enter your account number ")
    f=open(val+".txt","r")
    r=f.read()
    r1=r.split("\n")
    if(int(r1[4])==0):
        va=str(randint(1000,9999))
        server.sendmail('pythondemo3@gmail.com',r1[7],"your high security OTP IS : "+va)
        otp=input("enter otp")
        if(va==otp):
            os.remove(val+".txt")
            print("Your  account is deleted")
            
        else:
            close_ac()
    else:
        print("withraw all your money!!")
        UPI()

def choose():   
 print("enter the choise\n1.create account\n2.CREATE UPI ID AND PASSWORD\n3.banking transaction\n4.set green pin\n5.number of accounts in bank\n6.close account\n7. exit") 
 choice=int(input())
 if(choice==1):
    account()  
 elif(choice==2):
     UPI_c()
 elif(choice==3):
    UPI()
 elif(choice==4):
    gp()   
 elif(choice==5):
    n_ac()    

 elif(choice==6):
    close_ac()
 elif(choice==7):
    f=open("99412.txt","r")
    print(f.read())
    print("\n**************BANK MANAGEMENT SYSTEM******************\n")
    print("\t\tby: ASHLESHA ,DHRUVA ,ARUN")
    choose()    
 else:
    print("enter valid number 1-7")
    choose()      
choose()    