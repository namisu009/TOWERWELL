# 0. 소프트웨어설계기초 2분반 1조 비극탑

![main_page_01](https://github.com/user-attachments/assets/41c82b67-d227-4ae1-aca7-6a9b96ff7115)


# 1. 🛠️초기 세팅

## (1) ⬇️필수 다운로드 요소

게임을 정상적으로 실행하기 위해서 받아야하는 파일입니다.


[ASCIIART.zip](https://prod-files-secure.s3.us-west-2.amazonaws.com/ec7b2ff7-5393-4db9-a207-431881ce65c6/b222d34e-dbad-43ff-bcc7-d2f0c8008455/ASCIIART.zip)

[OpenCV-2.3.0.zip](https://github.com/user-attachments/files/18204175/OpenCV-2.3.0.zip)

설명은 아래 이미지를 참고하시면 됩니다.

![image](https://github.com/user-attachments/assets/4d1d7980-ab70-49da-b8f2-3339eabebac8)

![image (1)](https://github.com/user-attachments/assets/554ac1fb-5bea-4f3d-8d66-bb0c472cfd9b)

![사용방법](https://github.com/user-attachments/assets/f14287df-bf87-4d9b-acff-bfd9f52a5163)

![처음실행할때](https://github.com/user-attachments/assets/5573ca6e-3dce-4bcf-a68a-9c6098b4e5ab)

https://www.microsoft.com/en-us/download/details.aspx?id=26999 
에러 날 때 다운로드 받기 (3번 문항 참고)

## (2) 🔧필수 설정


위의 요소들을 다운받고 코드를 푸시받을 때, Branches에서 "real" branch를 풀 받으면 됩니다.
풀을 실행한 후, 

![스크린샷 2024-12-20 221430](https://github.com/user-attachments/assets/1de52f48-4646-40ff-bc38-7f1f9d690a48)

좌측 상단에서 위 사진과 같게 설정을 바꾸시고 한번 프로그램을 실행합니다.

이후 TOWERWELL 파일로 들어가 Debug파일의 SW설계기초프로젝트.exe. 파일을 우클릭하여
속성을 누릅니다.
호환성 탭에서 "관리자 권한으로 이 프로그램 실행" 탭을 활성화 시키고, 다시 프로그램을 실행합니다.

이후 콘솔창의 테두리를 우클릭 후 속성탭을 누릅니다.

![스크린샷 2024-12-20 221637](https://github.com/user-attachments/assets/fd90ed3c-0f6d-425d-aece-a1b3c476e71c)


![스크린샷 2024-12-20 221626](https://github.com/user-attachments/assets/ef0f33db-2aed-4039-9c42-c3f37257adc8)


위 사진과 같게 세팅을 하면 필수 설정은 마무리됩니다!


# 2. 🎮How to play

비극탑은 퍼즐맵과 플랫포머형 점프맵이 어우러진 노벨형 게임입니다.

탑의 분위기와 스토리의 반전에 몸을 맡기고 재밌게 플레이 하시길 바랍니다!

    기본적인 조작키
    
  ![arrow](https://github.com/user-attachments/assets/e00150b0-d4e6-4a83-aab7-3c8d258c12a7)

    위 방향키 : 점프
    좌우 방향키 : 좌우 이동
    스페이스바 : 대시, 퍼즐 및 오브젝트 상호작용
    F키 : 벽 타기

# 3. 🖥️역할 및 작업 분담

|  |  |  |
|-----------------|-----------------|-----------------|
| 남희수 | <ul><li>프로젝트 계획 및 관리</li><li>개발의 전체척인 총괄</li><li>일러스트 씬 제작</li></ul>|조장|
| 이  산 | <ul><li>캐릭터 및 맵 도트 그래픽 제작</li><li>점프맵 기획 및 제작</li></ul>|그래픽|
| 박준현 |<ul><li>시나리오 제작</li><li>퍼즐맵 기획</li><li>회의록 작성 및 발표</li><li>스테이지 추가 및 연결</li></ul>|기획|
| 전서희 | <ul><li>UI 클래스 제작</li><li>애니메이션 클래스 제작</li><li>보고서 작성</li></ul>|개발|


# 4. ✏️협업 도구

|  |  |
|-----------------|-----------------|
| Git    |  <img src="https://github.com/user-attachments/assets/483abc38-ed4d-487c-b43a-3963b33430e6" alt="git" width="100">    |
| Notion    |  <img src="https://github.com/user-attachments/assets/34141eb9-deca-416a-a83f-ff9543cc2f9a" alt="Notion" width="100">    |


# 5. 프로젝트 구조

![func](https://github.com/user-attachments/assets/7ba4e0bc-2cb6-429d-980e-e9ab601c4fd5)

# 6. 🌳개발 브랜치

- real Branch
    - 모든 코드 작성 및 수정을 수행하는 곳입니다.
    - 모든 기능 개발 및 배포는 이 브랜치에서 이루어집니다.


 # 7. 🐪🐍명명 규칙 (Name Convention)
   헤더 파일 및 클래스 : PascalCase (Ex. GameObjectManager.h, Class SceneManager ...

   
   함수 : camelCase (Ex. addScene(string id, Scene scene), setCompletedSceneDialog(~,~); ...)

   
   소스파일 (src) : snake_case (Ex. S7_M3_PZ_01_02.png, S8_M1_PZ_DT_02_01.png .. )

   소스파일의 각 단어의 뜻은 다음과 같이 명명하여 직관적으로 표현 (x는 숫자를 의미한다.)
   Sx: stage x

   SCx: scene x
   
   PZ(x): puzzle room or xth puzzle itself
   
   JP: jump room
   
   DL_xx_xx: xxth scene xxth dialog
   
   DPZxx: xxth dummy puzzle ifself
   
   Mx: Stage x h map
   
   DT: 디테일 씬 (화면 전체 표시되는 그림 or 게임 화면에 출력되는 obj)

  ex)
  S7_M2_PZ_02 : 스테이지 7의 두번째 퍼즐맵의 두번째 obj

S7_M2_PZ1_DL_00_01 : 스테이지 7의 두번째 방의 첫번째 퍼즐에 0번째 씬의 첫번째 대사

S1_M1_PZ_DT_01 : 스테이지 1의 첫번째 방의 퍼즐의 디테일 씬 01

 
