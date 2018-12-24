# update infomation (unreal engine4 plugin v0.21)

*Actor Type에서 ActorComponent Type으로 변경되었습니다. 
-현재 개발중인 컨텐츠의 Player에 Component를 추가해서 사용하시면 되겠습니다. 
-Player에 Component로 추가해서 사용하게 되면서 Player를 따로 Attach하지 않아도 됩니다.

*Component로 변경되면서 on/off기능을 제공합니다.  
-MoskitComp의 bool Type variable m_bisActive
-m_bisActive == true >>On // m_bisActive ==false >>Off

