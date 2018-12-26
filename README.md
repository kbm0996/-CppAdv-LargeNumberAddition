# 큰 수 덧셈
## 📢 개요
 C언어에서 각각의 자료형은 표현할 수 있는 값의 범위에는 한계가 있다.
 
| Data Type | Size | Range |
|:--------:|:--------:|--------|
| char | 1 Bytes | -128 ~ 127 |
| short | 2 Bytes | -32,768 ~ 32767 |
| int | 4 Bytes | -2,147,483,648 ~ 2,147,483,649 |
| long | 4 Bytes | -2,147,483,648 ~ 2,147,483,649 |
| unsigned char | 1 Bytes | 0 ~ 255 |
| unsigend short | 2 Bytes | 0 ~ 65,535 |
| unsigned int | 4 Bytes | 0 ~ 4,294,967,295 |
| unsigned long | 4 Bytes | 0 ~ 4,294,967,295 |
| float | 4 Bytes | 1.2E-38 ~ 3.4E38 |
| double | 8 Bytes | 2.2E-308 ~ 1.8E308 |
**table 1. DataType Size, Range (32bit)
 
 따라서, 해당 범위를 넘어가는 숫자들 간의 연산을 한다면 오버플로우가 발생할 수 있다.
 
  ![capture](https://github.com/kbm0996/Simple-Text-Simulation-Game/blob/master/GIF.gif?raw=truee)
  
  **figure 1. Text Simulation (animated gif)*  
  
## 🅿 주요 소스 
- **게임 매니저 클래스**

      class GameManage
      {
      private:
       /* 생략 */
      public:
       GameManager();
       virtual ~GameManager() {}
       
       // 외부에서 호출하는 함수
       bool Running();   

      protected:
      // 생성자에서 호출하는 함수
       bool LoadEvent();  // *Event.txt를 불러오는 함수
       bool LoadSelect(); // *Select.txt를 불러오는 함수
       
       // 내부에서 호출하는 함수
       bool SceneView(int EventID);
       int MoveEvent(int EventID);

      private:
       st_EVENT	 _stEvent[en_MAX_EVENT]; // 이벤트들을 저장하는 구조체
       st_SELECT	 _stSelect[en_MAX_SELECT]; // 선택지들을 저장하는 구조체

       int _iEventID; // 현재 가리키는 이벤트의 식별번호
      };

