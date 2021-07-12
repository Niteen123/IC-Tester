int ip1=2; // defining input pins of ic globally
int ip2=3;
int op=5; // defining output pin of ic globally
boolean tt[4]={false,false,false,false};// defining an array to comapre truth table
int i;
void setup() 
{
// put your setup code here, to run once: 
    pinMode(ip1,OUTPUT); 
    pinMode(ip2,OUTPUT); 
    pinMode(A0,OUTPUT); 
    pinMode(A1,OUTPUT); 
    pinMode(A2,OUTPUT); 
    pinMode(A3,OUTPUT); 
    pinMode(A4,OUTPUT); 
    pinMode(op,INPUT);
 }
void ICInputs() 
{
    for(i=0;i<4;i++) 
    {
        switch(i) 
        {
            case 0: 
            digitalWrite(ip1,LOW); 
            digitalWrite(ip2,LOW); 
            delay(50); 
            tt[i]=digitalRead(op); 
            break;

            case 1: 
            digitalWrite(ip1,LOW); 
            digitalWrite(ip2,HIGH); 
            delay(50); 
            tt[i]=digitalRead(op); 
            break;

            case 2:
            digitalWrite(ip1,HIGH); 
            digitalWrite(ip2,LOW); 
            delay(50); 
            tt[i]=digitalRead(op); 
            break;

            case 3: 
            digitalWrite(ip1,HIGH); 
            digitalWrite(ip2,HIGH); 
            delay(50); 
            tt[i]=digitalRead(op); 
            break;

            } 
    }
}
int nor() 
{
    pinMode(ip1,INPUT);
    pinMode(op,OUTPUT);
    for(i=0;i<4;i++) 
    {
        switch(i)
        {
            case 0: 
            digitalWrite(op,LOW); 
            digitalWrite(ip2,LOW);
            delay(50); 
            tt[i]=digitalRead(ip1); 
            break;
            case 1: 
            digitalWrite(op,LOW); 
            digitalWrite(ip2,HIGH); 
            delay(50); 
            tt[i]=digitalRead(ip1); 
            break;

            case 2: 
            digitalWrite(op,HIGH); 
            digitalWrite(ip2,LOW);
            delay(50); 
            tt[i]=digitalRead(ip1); 
            break;
            
            case 3: 
            digitalWrite(op,HIGH); 
            digitalWrite(ip2,HIGH); 
            delay(50); 
            tt[i]=digitalRead(ip1); 
            break;
        } 
    }
    if(tt[0]==HIGH && tt[1]==LOW && tt[2]==LOW && tt[3]==LOW) 
    return 1;
    else
    return 0;
}
int nott() 
{
    pinMode(ip2,INPUT); 
    for(i=0;i<2;i++)
    {
        switch(i)
        {
            case 0: 
            digitalWrite(ip1,HIGH); 
            tt[i]=digitalRead(ip2); 
            delay(50);
            break;
            
            case 1: digitalWrite(ip1,LOW); 
            tt[i]=digitalRead(ip2); 
            delay(50);
            break;
        }
  }
  if(tt[0]==LOW && tt[1]==HIGH)
  return 1; 
  else
  return 0; 
  }
void loop() 
{
 // put your main code here, to run repeatedly: 
 ICInputs();
 // for AND gate
 if(tt[0]==LOW && tt[1]==LOW && tt[2]==LOW && tt[3]==HIGH)
   digitalWrite(A0,HIGH);
   // for OR gate
   else if(tt[0]==LOW && tt[1]==HIGH && tt[2]==HIGH && tt[3]==HIGH) 
   digitalWrite(A1,HIGH);
    // for NAND gate
    else if(tt[0]==HIGH && tt[1]==HIGH && tt[2]==HIGH && tt[3]==LOW) 
    digitalWrite(A2,HIGH);
    // for EX-OR
    else if(tt[0]==LOW && tt[1]==HIGH && tt[2]==HIGH && tt[3]==LOW) 
    digitalWrite(A3,HIGH);
    // for EX-NOR
    else if(tt[0]==HIGH && tt[1]==LOW && tt[2]==LOW && tt[3]==HIGH)
    digitalWrite(A4,HIGH); 
    else
    {
        pinMode(ip1,INPUT); pinMode(op,OUTPUT);
        if(nor()==1) 
        {
            digitalWrite(A0,HIGH); digitalWrite(A1,HIGH); digitalWrite(A2,HIGH);
        }
        else if(nott()==1)
        { 
            digitalWrite(A2,HIGH); digitalWrite(A3,HIGH); digitalWrite(A4,HIGH);
        } 
        else 
        {
            while(1)
            { 
                digitalWrite(A0,HIGH); 
                digitalWrite(A1,HIGH); 
                digitalWrite(A2,HIGH); 
                digitalWrite(A3,HIGH); 
                digitalWrite(A4,HIGH); 
                delay(1000); 
                digitalWrite(A0,LOW); 
                digitalWrite(A1,LOW); 
                digitalWrite(A2,LOW); 
                digitalWrite(A3,LOW); 
                digitalWrite(A4,LOW); 
                delay(1000);
            }
        }
    }
}