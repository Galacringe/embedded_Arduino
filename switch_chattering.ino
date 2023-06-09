//채터링과 스위치
unsigned long curr_time = 0;
unsigned long pre_time;
int sw_cnt = 0;
int sw_lock = 0;
void setup() {
  Serial.begin(9600);
  pinMode(12, INPUT_PULLUP); // 풀업 저항을 이용해서 입력받음
  pinMode(13, OUTPUT); // 

}
void loop() {
  curr_time = millis();
  if (pre_time != curr_time){ // 1ms마다 조건 충족
    pre_time = curr_time;
    
    if(digitalRead(12)==0){
      if(sw_cnt++ >= 50 && sw_lock == 0){ // 회로 설계상 0이 true, 스위치가 눌린 것이 Low다.
        sw_lock = 1; // 잠금 걸기
        digitalWrite(13, digitalRead(13)^1);
      }
    }
    else {
      sw_lock = 0; // 떼면 잠금 
      sw_cnt = 0;
    }    
  }
}
