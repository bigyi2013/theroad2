L1=Link('d', 0.08, 'a', 0, 'alpha', pi/2);%L1为连杆1，‘a'为连杆1长度，’d'为关节2相对1偏长，‘alpha'为关节2相对1的扭角，’theta’为关节1的转角
L2=Link('d',0,'a',0.3,'alpha',-pi/2);
L3=Link('d',0,'a',0,'alpha',pi/2);
L4=Link('d',0.17+0.07+0.06,'a',0,'alpha',pi/2);
%L5=Link('d',0,'a',0.06,'alpha',0);
roldm=SerialLink([L1,L2,L3,L4],'name','oldm');
roldm.links(1,3).offset=pi/2;%设定关节3初始位置
%roldm.links(1,1).offset=-pi/2;%设定关节1初始位置
%roldm.links(1,4).offset=pi/2;%设定关节4初始位置
%%roldm.links(1,5).offset=pi/2;%设定关节5初始位置
roldm.base=transl(0,0.23,0)*trotx(pi/2);%设定关节1与基坐标系相对位置
roldm.teach([0 0 0 0]);