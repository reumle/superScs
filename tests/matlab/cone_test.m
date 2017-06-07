clc
clear all;

K.q = 4;

A(1,1) = 0.3;
A(4,1) = -0.5;
A(2,2) = 0.7;
A(4,2) = 0.9;
A(3,3) = 0.2;

b = [0.2; 0.1; -0.1; 0.1];
c = [1;-2;-3];

data.A = sparse(A);
data.b = b;
data.c = c;

params.max_iters = 24;
params.nominal = 0;
params.eps = 1e-5;
params.do_super_scs = 1;
params.alpha = 1.5;
params.scale = 1;
params.verbose = 1;
params.normalize = 1;
params.direction = 100;
params.beta = 0.9;
params.c1 =1.0-1e-4;
params.c_bl = 0.999;
params.k0 = 1;
params.k1 = 0;
params.k2 = 0;
params.ls = 10;
params.sigma = 1e-2;
params.thetabar = 0.1;
params.rho_x = 1;
params.memory = 10;
params.sse = 0.999;
params.tRule=3;


params.max_iters = 204;
[x1,y1,s1,info1]=scs_direct(data, K, params);
[x2,y2,s2,info2]=superscs(data, K, params);