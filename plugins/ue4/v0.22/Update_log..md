# Update infomation (unreal engine4 plugin v0.22, 220128)

- UE 4.22 ~ 4.26 버전 VR 프로젝트에 Moskit Plugin 적용 시 FOV 값이 비정상적인 값으로 추출되는 문제 수정

# Update infomation (unreal engine4 plugin v0.22, 210422)

- UE 4.22 이후 버전(4.23 ~ 4.26)에 Moskit Plugin을 적용할 수 있도록 새로 업데이트
 
 # update infomation (unreal engine4 plugin v0.22)

## 11/29 추가사항

- 컨텐츠 뷰 포트에 정보를 출력해주는 블루프린트 위젯을 추가하였습니다. (v4.20)

- 가능하면 최대한 화면에서 짤리지않게 카메라와 가까이 배치시키고 scale을 조정해주시면 되겠습니다.

## 11/14 버그수정

- 패키징이 되지 않던 버그 수정

## 패키징 작업

1. 편집 - 프로젝트셋팅 - 패키징탭 : 'Build Configration'을 'Shipping'으로 설정, 'Full Rebuild' 체크

2. 편집 - 프로젝트셋팅 - 지원 플랫폼 탭 : '모든 플랫폼' 체크해제, '윈도우'만 체크

## 패키징 후

1. exe파일에 같이 존재하는 폴더(프로젝트이름)에 순서대로 진행

2. 'Plugins'폴더 생성, 그 안에 'Moskit'폴더 생성, 그 안에 MoskitPlugin에 VideoTool폴더 복사 후 붙여넣기

## 셋팅 방법

- BlueprintFunctionLibrary로 제공됩니다.
		
	* > void StartMoskit(FString strOutputFilePath, bool bisConnectedToHardware)

		* FString strOutputFilePath, : *.bin / *.avi 파일이 저장될 경로입니다.( **절대 경로를 입력해주세요** )

		* bool bisConnectedToHardware : VR컨텐츠에 이용되는 하드웨어의 자이로센서값을 받아올 때 사용하는 변수

		* Plugin의 시작지점입니다. 		

		* 컨텐츠의 플레이 시작지점에 배치시켜주세요.


	* > void RunMoskit(AActor* pPlayer, ,bool bisActive, float DeltaTime, float fFloortoCameraHeight)

		* AActor* _pPlayer : Player가 조종하는 Pawn 래퍼런스를 연결해주세요.

		* bool bisActive  : ON /OFF에 사용될 bool타입의 변수입니다.( **bisActive  true == on / false == off** )

		* float DeltaTime : Plugin이 동작하는 컨텐츠의 Tick() deltaTime을 연결해주세요

		* float  fFloortoCameraHeight : 컨텐츠와 카메라의 높이 차이

		* 컨텐츠를 플레이하는 구간에 배치시켜주세요.

	
	* > void EndMoskit()

		* Plugin을 종료시키는 Function입니다.	

		* 컨텐츠 플레이가 종료되는 시점에 배치해주세요.

		* ( **bisActive는 pause의 개념이라면, EndMoskit()은 Stop이라고 생각하시면 되겠습니다** )

## 주의사항
1. 분석하고자 하는 레벨에 대하여 Tick()함수에 RunMoskit()을 배치해주세요.

2. StartMoskit() / EndMoskit()은 컨텐츠당 한번만 배치해주시기 바랍니다. 
( RunMoskit() 은 다수의 레벨또는 서브레벨에 대해서 추가적으로 배치가능합니다.)

3. 각 매개변수를 전부 넣어주셔야 합니다


## 기타

1. 시작 시 비디오툴 실행으로 인한 프레임드랍 수정.

2. 버그 수정 및 편의성 업데이트

	* > 각 레벨 구간에 모스킷을 배치할 수 있습니다.
	 
	* > HMD 분석 데이터값이 제대로 들어가지 않는 점 수정
