                ## the program which reads the JSON data containing name aadhar number and blood pressure of patients  and protect them using blockchain 
from hashlib import sha256
import json
import time
class block:
    def __init__(self,timestamp,data,previous_hash=' '):#constructor of block class
        self.timestamp=timestamp
        self.data=data
        self.previous_hash=previous_hash
        self.hash=self.calculate_code()
        #self.hash2=self.own()

    def calculate_code(self):#a function which encrypts the data and finally return the hashcode
        hghgs=(self.data[0]+self.data[1]+self.data[2]+self.data[3]) #add all the strings of a single record
        sum=0
        a=0
        for i in hghgs:
            sum=sum+(ord(i)) #it converts the each character to it's corresponding integer value
            sum=sum+a*a
            a=a+1
        abs=self.data[1] #taken aadhar number 
        sum2=str(sum)    #sum of all values of a record
        print(sum2+abs)  # addition of aadhar and sum 
        return sha256(((str(sum2+abs))).encode()).hexdigest() #it returns the hashcode

class Blockchain():
    def __init__(self): #constructor fo blockchain classs
        self.chain=[self.start()]

    def start(self): #a function to create a block when no data is there
        return block(time.ctime(),"This is the zeroth block","0000")

    def add_to_blockchain(self,data): #this function adds data to the blockchain
       node=block(time.ctime(),data,self.chain[-1].hash)
       self.chain.append(node)

    def p_blockchain(self): #a function that prints the data of the blockchain 
        for i in range(len(self.chain)):
            print("{\n","block no.=", i ,"\ntimestamp=",
				        self.chain[i].timestamp,"\ndata=", 
				       		self.chain[i].data, "\npreviousHash=",
				       		 self.chain[i].previous_hash,"\nhash=",
				       		    self.chain[i].hash,"\n}\n")

blockchain= Blockchain()#object of blockchain class is created
f=open('data.json',) #json file loaded
data = json.load(f)
for i in data['pat_details']:
    name=i['name']
    adhar=i['adhar']
    city=i['city']
    b_p=i['b_p']
    data =[name,adhar,city,b_p]
    blockchain.add_to_blockchain(data)
blockchain.p_blockchain()#blockchain print function is called