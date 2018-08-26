%L1为连杆1，‘a'为连杆1长度，’d'为关节2相对1偏长，‘alpha'为关节2相对1的扭角，’theta’为关节1的转角
L1=Link('d', 0.08, 'a', 0, 'alpha', pi/2);
L2=Link('d',0,'a',0.3,'alpha',-pi/2);%设置L2连杆
L3=Link('d',0,'a',0,'alpha',pi/2);%设置L3连杆
L4=Link('d',0.17+0.07+0.06,'a',0,'alpha',pi/2);%设置L4连杆
roldm=SerialLink([L1,L2,L3,L4],'name','robot4');%设置名字，以后simulink需要用到
roldm.base=transl(0,0.23,0)*trotx(pi/2);%设定关节1与基坐标系相对位置
roldm.teach([0 0 0 0]);
