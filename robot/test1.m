mdl_puma560
dq = [0:0.001:1]';
m=length(dq);
A=zeros(m,6);
A(:,1)=dq;
B=zeros(m,6);
for i=1:m
    B(i,:)=qn;
end
C=A+B;
T0=p560.fkine(C);
p=transl(T0);
%plot(p(:,1),p(:,2))

p560.plot(C)
%qn=qn+[1:0.1 0 0 0 0 0];
%T0=p560.fkine(qn);
%p=transl(T0);
%p(:,1)
%p560.plot(qn)