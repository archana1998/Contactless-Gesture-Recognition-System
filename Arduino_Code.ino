int sensorL = 3;
int sensorR = 6;
bool r=false,l=false,m=false;
int iL,iR,n=0;

void setup() {
//put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(sensorL,INPUT);
  pinMode(sensorR, INPUT);

}

void loop() {
  Serial.begin(9600);
  iL = digitalRead(sensorL);
  iR = digitalRead(sensorR);
  if(iL == 0 && iR == 1);
  {
   l = true;
   m = true;
  }
  if(l == true)
  {
   iR = digitalRead(sensorR);
   if(iR==0)
    r = true;
   }
   
  if(m==false && r==true && l==true)
  {
    Serial.println("Right swipe!");
    r = false;
    l = false;
    m = false;
    delay(100);
   }
   if(iR==0 && iL==1)
   {
    r = true;
    m = false;
   }
   if(r==true)
   {
    iL = digitalRead(sensorL);
    if(iL==0)
    {
      l=false;
    }
   }
   
   if(m==true && r==true && l==false)
   {
    Serial.println("Left swipe!");
    r = false;
    l = false;
    m = false;
    delay(100);
   }
   if(iR==0 && iL==0)
   {
    m = true;
    r = true;
    l = true;
   }
   if(m==true && r==true && l==true)
   {
    Serial.println("Push");
    r = false;
    l = false;
    m = false;
    n = 1;
    delay(800);
   }
   
   if(n==1)
   {
    iL = digitalRead(sensorL);
    iR = digitalRead(sensorR);
    if(iL==1 && iR==1)
    {
      Serial.println("Pull");
      n = 0;
    }
   }
   delay(200);
   
