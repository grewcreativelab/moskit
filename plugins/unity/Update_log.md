# Bug fix (Unity plugin v0.22.1, 181129)

- AndroidOS에서  bin 파일이 정상적으로 만들어지지 않는 현상이 수정되었습니다.

- 녹화프로그램 경로가 비정상적이였던 부분이 수정되었습니다.

- Scene이 넘어갈 때 MainCamera를 잡지 못하는 현상을 수정하였습니다.

# Update infomation (Unity plugin v0.22.1, 181129)

- Video녹화 OnOff 추가

- 카메라를 Plugin 내부에서 찾게 변경

- DontDestroyOnLoad gameObject로 변경

## 사용 방법 (Moskit UnityPlugin)

1. 인스펙터의 각 매개변수 설정
	
	* > fFloorToCameraHeight : 월드에 배치된 카메라와 바닥의 높이 차이

	* > strOutputFilePath : 데이터 (.bin)파일과 영상(.avi)파일이 출력될 경로

	* > ScaleRatio : 컨텐츠의 축척비율 (축척비, default (Unity) . 1unit == 1m)

	* > bisActive : Plugin ON/OFF기능	

	* > bVideoOnOff : Plugin의 녹화ON/OFF기능 ( Multiple Display Streaming환경에서는 녹화 기능이 원할하지 않을 수 있습니다. )

	* > bisConnectedToHardware : VR컨텐츠에 이용되는 하드웨어의 자이로센서값을 받아올 때 사용하는 변수

	* > bisConnectingLog : hardware 연결 상태 로그 출력용 변수 (true 시 Log출력)

2. Scene의 시작부분에 하나만 배치합니다. ( DontDestroyOnLoad )

3. 콘텐츠가 종료되지 않는 프로그램이라면, 추가 작업이 필요합니다.

	* > MSPlugin 오브젝트의 MoskitPluginMain Component의 moskit_state변수를 콘텐츠가 끝나는 시점에 'End'로 설정해주세요.

## 주의 사항	

1. 각 매개변수를 설정하지 않으면 데이터 파일 처리가 원활히 이루어지지 않아 분석에 문제가 생길 수 있습니다.
 
## 기타

# update infomation (Unity plugin v0.22)

- 사용 방법 변경 

- Hardware 연결기능 추가