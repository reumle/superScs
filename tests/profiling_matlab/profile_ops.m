function o = profile_ops()

o.alpha = 1.5;
o.beta = 0.5;
o.c1 = 0.9999;
o.c_bl = 0.999;
o.cg_rate = 2;
o.direction = 100;
o.do_super_scs = 1;
o.k0 = 0;
o.k1 = 1;
o.k2 = 1;
o.ls = 10;
o.memory = 50;
o.normalize = 1;
o.rho_x = 0.001;
o.scale = 1;
o.sigma = 0.01;
o.sse = 0.999;
o.thetabar = 0.12;
o.verbose = 0;
o.do_record_progress = 0;
o.use_indirect = 1;
o.max_iters = 5000;
o.warm_start = 0;
o.dumpfile = 'temp.mat';