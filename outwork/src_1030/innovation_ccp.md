# Manual



## 1. All Guide

먼저 python을 설치합니다. : https://www.python.org/downloads/



![1572427240617](C:\Users\test\AppData\Roaming\Typora\typora-user-images\1572427240617.png)

여기서 Dec, 24, 2018 릴리즈 버전인 python 3.6.8을 설치합니다.



![1572427296532](C:\Users\test\AppData\Roaming\Typora\typora-user-images\1572427296532.png)

밑으로 내려가면 Files에 있는 Windows x86 excutable installer를 설치해줍니다.

![1572427444207](C:\Users\test\AppData\Roaming\Typora\typora-user-images\1572427444207.png)

>  매뉴얼 작성자는 3.6.x 버전이 설치되어있어 3.8로 진행하지만 설치방법은 같습니다.

Add Python 3.x to PATH를 체크한후 Customize installation 을 설치해줍니다.

![1572427512040](C:\Users\test\AppData\Roaming\Typora\typora-user-images\1572427512040.png)

전부 체크한후 

![1572427523913](C:\Users\test\AppData\Roaming\Typora\typora-user-images\1572427523913.png)

다음과 같이 체크한후 설치합니다.

그이후, 윈도우 검색에 명령프롬포트를 검색한후, 관리자 권한으로 실행합니다.

![1572427578647](C:\Users\test\AppData\Roaming\Typora\typora-user-images\1572427578647.png)

pip install PyQt5 를 이용하여 PyQt5 라이브러리를 설치합니다.

![1572427634309](C:\Users\test\AppData\Roaming\Typora\typora-user-images\1572427634309.png



2. 두번째로, mongoDB를 설치해줍니다. : https://www.mongodb.com/download-center/community

   ![1572427731210](C:\Users\test\AppData\Roaming\Typora\typora-user-images\1572427731210.png)

   Server 목록을 설치하여 Community Server를 다운로드합니다.

   별도의 선택없이 설치해주지만, **설치 경로를 꼭 기억해 두십시오.**
   
   설치 후에는 아래의 매뉴얼을 따라 주십시오 : https://javacpro.tistory.com/64
   
   > 이곳에서 path 설정을 할때의 매뉴얼과는 살짝 다른점이 있습니다.
   >
   > 설치 된 mongoDB 이후의 경로는 같지만 설치된 경로가 다르므로
   >
   > 설치된경로\mongoDB\bin 으로 경로를 설정해주면 되며, 이후 가이드에 있는 모든 경로 설정은 다음과 같이 따라주십시오.
   
3. 세번 째로 robomongo를 설치합니다. : https://robomongo.org/download

   이 프로그램으로 database를 효율적으로 관리할 수 있습니다.

   ![1572427850760](C:\Users\test\AppData\Roaming\Typora\typora-user-images\1572427850760.png)

우측 하단에 있는 Robo 3T만 다운받아줍니다.

이것도 별도의 선택없이 설치해줍니다.

설치 후 접속하게 된후에는 아래의 매뉴얼을 따라주십시오.

https://javacpro.tistory.com/65

> 5. Database 생성 전인 4. 까지 따라주시면 됩니다.



4. python과 mongoDB를 연결해주기 위해 명령프롬포트를 다시 관리자 권한으로 실행합니다.

   ![1572428068025](C:\Users\test\AppData\Roaming\Typora\typora-user-images\1572428068025.png)

pip install pymongo를 입력하여 설치해 줍니다.

그러면 기본적인 설정은 완료 되었습니다.

관리자는 flask라는 서버 관리가 필요합니다.



## 2. Admin Guide

1. Flask를 설치해야합니다. 관리자 권한으로 명령프롬포트를 실행합니다.

![1572428147769](C:\Users\test\AppData\Roaming\Typora\typora-user-images\1572428147769.png)

pip install flask 를 통해서 flask 서버 라이브러리를 설치해줍니다.



2. 사용자와 관리자가 프로그램을 사용하기 위해서는, flask라는 서버를 통해 서버를 열어주어야합니다. 데이터베이스와 유저간의 중개자 역할을 수행합니다.

   먼저, python 파일이 전부 들어가있는 디렉토리로 이동해야합니다. 디렉토리를 알수 있는 방법은 다음과 같습니다:

   ![1572428274006](C:\Users\test\AppData\Roaming\Typora\typora-user-images\1572428274006.png)

파일 탐색기로 python 파일이 저장된 곳으로 이동후 위의 주소를 복사합니다. 필자의 주소는 다음과 같습니다:

> C:\Users\test\workspace\outworker\src_1030

이 주소를 명령 프롬포트에 입력하여 디렉토리로 이동합니다.

명령어는 다음과 같습니다:

> cd C:\Users\test\workspace\outworker\src_1030

이곳에서 python server.py를 실행해주십시오.

**서버는 계속 실행 하고 있어야 합니다. 명령프롬포트를 종료하면, 서버도 종료됩니다. 절대 명령 프롬포트를 종료하지 마십시오.**



그 이후 명령 프롬포트를 **새로 켜주신후에** cd C:\Users\test\workspace\outworker\src_1030 명령어를 사용하셔서 다시 디렉터리로 들어가줍니다.

그 이후, python main.py 명령어를 이용하여 프로그램을 실행시켜줍니다.

![1572428818933](C:\Users\test\AppData\Roaming\Typora\typora-user-images\1572428818933.png)

다음과 같은 프로그램이 실행됩니다.

IP ADDRESS 와 Netwrok Port, DomainName에 기본으로 설정되어있는 값은 localhost의 기본값입니다. 서버를 킨 컴퓨터에서 진행하는 경우 이대로 진행이 가능하며, 만약 다른 사용자 컴퓨터에서 사용할 경우 관리자 IP를 얻어야합니다. **관리자 IP는 관리자 컴퓨터, 명령 프롬포트에서 ipconfig를 하여 IPv4 주소를 사용합니다. 또한, 설정을 초기화 하고 싶을 경우 Local Domain 버튼을 눌러주면 초기화 됩니다.** 

> userName은 사용자가 원하는 문자열을 넣어주시면 됩니다.

그 이후, Connect 버튼을 누르면 서버와 연결됩니다.





![1572429041677](C:\Users\test\AppData\Roaming\Typora\typora-user-images\1572429041677.png)

이와 같은 메뉴가 생성됩니다.

여기서, Robo3T를 확인해줍니다.

![1572429087377](C:\Users\test\AppData\Roaming\Typora\typora-user-images\1572429087377.png)

![1572429097248](C:\Users\test\AppData\Roaming\Typora\typora-user-images\1572429097248.png)

다음과 같이 첫 실행에는 config 테이블만 있는것을 확인 할 수있습니다. 그이후 새로운 글을 작성하면 example 테이블이 생성됩니다. 다시 프로그램으로 돌아가 New 버튼을 클릭합니다.

![1572429295404](C:\Users\test\AppData\Roaming\Typora\typora-user-images\1572429295404.png)

이곳에서 제목과 내용을 작성할 수 있으며 submit을 통해 database에 전송합니다.



다시 Robo3T를 확인하십시오:

![1572429342363](C:\Users\test\AppData\Roaming\Typora\typora-user-images\1572429342363.png)

다음과 같이 sample Table이 생성된 것을 볼 수 있습니다.

> 새로고침은 connection1 과 같은 컴퓨터 아이콘을 더블클릭하면 새로고침이 됩니다.

![1572429399026](C:\Users\test\AppData\Roaming\Typora\typora-user-images\1572429399026.png)

sample > Collections > file 을 더블클릭하면 다음과 같이 글이 Database에 저장된 것을 확인 할 수 있습니다.



![1572429446991](C:\Users\test\AppData\Roaming\Typora\typora-user-images\1572429446991.png)

초기 화면으로 돌아왔다면, 아무 것도 없는 목록에 당황하시지 마시고, Refresh를 누르면 db에서 글을 가져옵니다.

![1572429527245](C:\Users\test\AppData\Roaming\Typora\typora-user-images\1572429527245.png)



다음과 같이 계속 생성 할 수 있습니다.

또한 글이 5개가 넘어간다면 최근 5개의 글만 확인 할 수 있습니다.

![1572429578802](C:\Users\test\AppData\Roaming\Typora\typora-user-images\1572429578802.png)

