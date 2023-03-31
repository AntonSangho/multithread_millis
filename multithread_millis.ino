const int t1_LED = 12;
unsigned int on_off = 0;

const int t2_LED = 11;
int t_high = 0; //초기화 

unsigned long t1_prev = 0; //이전시간
const unsigned long t1_delay = 500; //주기의 값

unsigned long t2_prev = 0; //이전시간
const unsigned long t2_delay = 4; //주기의 값


void setup() {
  pinMode(t1_LED, OUTPUT);
  pinMode(t2_LED, OUTPUT);
}

void loop() {
  unsigned long t1_now = millis(); //
  if(t1_now - t1_prev >= t1_delay){
    t1_prev = t1_now;

    on_off++;
    //Serial.println(t_high);
    if(on_off>1) on_off = 0;
    digitalWrite(t1_LED, on_off);
    
  }

  unsigned long t2_now = millis(); //
  if(t2_now - t2_prev >= t2_delay){
    t2_prev = t2_now;

    t_high++;
    //Serial.println(t_high);
    if(t_high>255) t_high = 0;
    digitalWrite(t2_LED, t_high);
    
  }
}
