int led = D0;

//Blink Function w/ optional delay
void blink(int led, int optDelay = 400)
{
    digitalWrite(led,HIGH);
    delay(optDelay);
    digitalWrite(led,LOW);
    delay(optDelay);
}

//Handler, The led blinks 3 times slowly when a wave is recieved
//The led blinks 6 times rapidly when a pat is recieved
void myHandler(const char *event, const char *data)
{
    if (strcmp(data,"wave")==0) {
    for (int i = 0;i < 3;i++)
        blink(led);
    }
    else if(strcmp(data,"pat")==0) {
    for (int i = 0;i < 6;i++)
        blink(led, 50);
    }
}




void setup() {
    pinMode(led, OUTPUT);
    //Particle ID
    Particle.subscribe("Deakin_RIOT_SIT210_Photon_Buddy", myHandler);
}
