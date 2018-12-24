# GREW MOSKIT Unity Plugin

*** Unity Plugin 사용법 https://youtu.be/TPO4TW9lC1w ***

[![MOSKIT Plugin Integration Guide for Unity](http://img.youtube.com/vi/uLR1RNqJ1Mw/0.jpg)](https://youtu.be/TPO4TW9lC1w)

	1. 다운받은 유니티 플러그인 패키지를 현재 개발중인 VR콘텐츠에디터를 실행합니다.

	2. 에디터의 Assets -> impoet package -> Custom Package -> Moskitpackage.unitypackage를 선택합니다.

	3. 에디터에 'Create Empty(GameObject)'를 생성합니다.

	4-1. 방법1) 

		'Add Component' -> 'MoskitPluginMain'검색, 추가
	
		추가한 'MoskitPluginMain'의 Inspector에 'MainCamera'에 

		프로젝트의 MainCamera를 드래그합니다. (Oculus기준 'CenterEyeAnchor')

		셋팅을 마무리 후 플레이 합니다.

	4-2. 방법2) 

		import후 추가된 'Moskit' 디렉터리에 'MoskitPlugin_Unity'DLL옆 화살표를 눌러서 'MoskitPluginMain'을 가져옵니다.

		Empty Object의 Inspector에 'MoskitPluginMain'를 드래그하여 Component를 추가한 후 
	
		'MainCamera'에 프로젝트의 MainCamera를 드래그합니다. (Oculus기준 'CenterEyeAnchor')

		셋팅을 마무리 후 플레이 합니다.

	5. 프로젝트 디렉터리에 추출된 *.bin 파일과 *.avi파일을 'MoskitVisualizer' 를 이용하여 어지럼증을 분석합니다.
