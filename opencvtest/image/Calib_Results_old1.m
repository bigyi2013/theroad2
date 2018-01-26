% Intrinsic and Extrinsic Camera Parameters
%
% This script file can be directly executed under Matlab to recover the camera intrinsic and extrinsic parameters.
% IMPORTANT: This file contains neither the structure of the calibration objects nor the image coordinates of the calibration points.
%            All those complementary variables are saved in the complete matlab data file Calib_Results.mat.
% For more information regarding the calibration model visit http://www.vision.caltech.edu/bouguetj/calib_doc/


%-- Focal length:
fc = [ 1341.312340825152400 ; 1337.664420955825100 ];

%-- Principal point:
cc = [ 676.556018866917840 ; 508.915738208677060 ];

%-- Skew coefficient:
alpha_c = 0.000000000000000;

%-- Distortion coefficients:
kc = [ -0.123668894761590 ; 0.137643611020096 ; 0.002806375033592 ; 0.002598200520498 ; 0.000000000000000 ];

%-- Focal length uncertainty:
fc_error = [ 4.174285031623619 ; 3.996700175096965 ];

%-- Principal point uncertainty:
cc_error = [ 7.163105773038615 ; 5.634225836262451 ];

%-- Skew coefficient uncertainty:
alpha_c_error = 0.000000000000000;

%-- Distortion coefficients uncertainty:
kc_error = [ 0.020140950527907 ; 0.156977060254169 ; 0.001117846770339 ; 0.001322494789250 ; 0.000000000000000 ];

%-- Image size:
nx = 1292;
ny = 964;


%-- Various other variables (may be ignored if you do not use the Matlab Calibration Toolbox):
%-- Those variables are used to control which intrinsic parameters should be optimized

n_ima = 90;						% Number of calibration images
est_fc = [ 1 ; 1 ];					% Estimation indicator of the two focal variables
est_aspect_ratio = 1;				% Estimation indicator of the aspect ratio fc(2)/fc(1)
center_optim = 1;					% Estimation indicator of the principal point
est_alpha = 0;						% Estimation indicator of the skew coefficient
est_dist = [ 1 ; 1 ; 1 ; 1 ; 0 ];	% Estimation indicator of the distortion coefficients


%-- Extrinsic parameters:
%-- The rotation (omc_kk) and the translation (Tc_kk) vectors for every calibration image and their uncertainties

%-- Image #1:
omc_1 = [ -2.481493e+00 ; -1.640906e+00 ; 5.745533e-01 ];
Tc_1  = [ -1.429284e+02 ; 1.388620e+01 ; 9.238153e+02 ];
omc_error_1 = [ 6.154100e-03 ; 3.904199e-03 ; 1.094295e-02 ];
Tc_error_1  = [ 4.938244e+00 ; 3.896463e+00 ; 2.956700e+00 ];

%-- Image #2:
omc_2 = [ -2.110475e+00 ; -2.259977e+00 ; 1.187998e-01 ];
Tc_2  = [ -1.659557e+02 ; -9.667594e+01 ; 5.954463e+02 ];
omc_error_2 = [ 4.653628e-03 ; 4.913712e-03 ; 1.026728e-02 ];
Tc_error_2  = [ 3.191308e+00 ; 2.544736e+00 ; 2.368165e+00 ];

%-- Image #3:
omc_3 = [ 1.826025e+00 ; 1.719997e+00 ; -1.103721e+00 ];
Tc_3  = [ -1.250472e+02 ; -3.137524e+01 ; 7.061850e+02 ];
omc_error_3 = [ 3.225422e-03 ; 4.691583e-03 ; 6.904214e-03 ];
Tc_error_3  = [ 3.779574e+00 ; 2.987239e+00 ; 2.089687e+00 ];

%-- Image #4:
omc_4 = [ -2.335920e+00 ; -1.389623e+00 ; 1.062721e+00 ];
Tc_4  = [ -1.315768e+02 ; 2.648036e+01 ; 9.801183e+02 ];
omc_error_4 = [ 5.853193e-03 ; 2.917221e-03 ; 7.813628e-03 ];
Tc_error_4  = [ 5.253583e+00 ; 4.136203e+00 ; 2.922408e+00 ];

%-- Image #5:
omc_5 = [ -1.915136e+00 ; -2.077395e+00 ; 8.464867e-01 ];
Tc_5  = [ -4.323232e+01 ; -3.877304e+01 ; 9.535766e+02 ];
omc_error_5 = [ 5.079054e-03 ; 4.501149e-03 ; 8.523271e-03 ];
Tc_error_5  = [ 5.081385e+00 ; 4.010094e+00 ; 2.873513e+00 ];

%-- Image #6:
omc_6 = [ -1.775503e+00 ; -2.264830e+00 ; 5.004391e-01 ];
Tc_6  = [ -1.412321e+02 ; -8.919023e+01 ; 8.625224e+02 ];
omc_error_6 = [ 4.596744e-03 ; 5.339714e-03 ; 9.074022e-03 ];
Tc_error_6  = [ 4.606490e+00 ; 3.661732e+00 ; 2.899597e+00 ];

%-- Image #7:
omc_7 = [ 1.845833e+00 ; 1.926593e+00 ; -6.497733e-01 ];
Tc_7  = [ -1.393782e+02 ; -6.522979e+01 ; 6.924507e+02 ];
omc_error_7 = [ 3.090578e-03 ; 4.572855e-03 ; 7.470139e-03 ];
Tc_error_7  = [ 3.697934e+00 ; 2.932099e+00 ; 2.302365e+00 ];

%-- Image #8:
omc_8 = [ 1.989128e+00 ; 2.061597e+00 ; -1.827765e-02 ];
Tc_8  = [ -1.242275e+02 ; -2.818239e+00 ; 9.197901e+02 ];
omc_error_8 = [ 6.706449e-03 ; 6.662684e-03 ; 1.351197e-02 ];
Tc_error_8  = [ 4.920749e+00 ; 3.896499e+00 ; 3.770070e+00 ];

%-- Image #9:
omc_9 = [ 2.021309e+00 ; 2.015641e+00 ; 1.277836e-01 ];
Tc_9  = [ -1.290270e+02 ; -6.209390e+01 ; 8.776146e+02 ];
omc_error_9 = [ 5.843413e-03 ; 5.859477e-03 ; 1.165007e-02 ];
Tc_error_9  = [ 4.700179e+00 ; 3.713786e+00 ; 3.595996e+00 ];

%-- Image #10:
omc_10 = [ 1.782179e+00 ; 1.687945e+00 ; 4.423459e-01 ];
Tc_10  = [ -1.680480e+02 ; -9.592703e+01 ; 5.808714e+02 ];
omc_error_10 = [ 4.161459e-03 ; 4.059377e-03 ; 6.405997e-03 ];
Tc_error_10  = [ 3.158200e+00 ; 2.494670e+00 ; 2.446924e+00 ];

%-- Image #11:
omc_11 = [ 2.434287e+00 ; 1.516716e+00 ; -1.024692e+00 ];
Tc_11  = [ -1.479575e+02 ; 3.848572e+00 ; 7.933391e+02 ];
omc_error_11 = [ 3.745035e-03 ; 4.283441e-03 ; 8.490029e-03 ];
Tc_error_11  = [ 4.254489e+00 ; 3.352641e+00 ; 2.414183e+00 ];

%-- Image #12:
omc_12 = [ 1.560685e+00 ; 1.994515e+00 ; 3.869383e-01 ];
Tc_12  = [ -1.258363e+02 ; -6.325294e+01 ; 7.379755e+02 ];
omc_error_12 = [ 4.237748e-03 ; 4.602266e-03 ; 7.010435e-03 ];
Tc_error_12  = [ 3.950565e+00 ; 3.140866e+00 ; 2.933009e+00 ];

%-- Image #13:
omc_13 = [ -1.125581e+00 ; -2.353052e+00 ; 6.659876e-01 ];
Tc_13  = [ -6.565278e+01 ; -1.740763e+02 ; 8.475565e+02 ];
omc_error_13 = [ 3.912894e-03 ; 5.309728e-03 ; 6.795039e-03 ];
Tc_error_13  = [ 4.557399e+00 ; 3.590393e+00 ; 2.818384e+00 ];

%-- Image #14:
omc_14 = [ -2.000314e+00 ; -2.146528e+00 ; 4.766748e-01 ];
Tc_14  = [ -1.217684e+02 ; -1.129155e+02 ; 6.767449e+02 ];
omc_error_14 = [ 4.575911e-03 ; 4.178125e-03 ; 8.765882e-03 ];
Tc_error_14  = [ 3.627568e+00 ; 2.857356e+00 ; 2.303957e+00 ];

%-- Image #15:
omc_15 = [ 1.956711e+00 ; 2.191873e+00 ; -4.062703e-01 ];
Tc_15  = [ -1.394438e+02 ; -8.288680e+01 ; 6.536679e+02 ];
omc_error_15 = [ 3.714561e-03 ; 4.885617e-03 ; 9.042826e-03 ];
Tc_error_15  = [ 3.488286e+00 ; 2.767194e+00 ; 2.317045e+00 ];

%-- Image #16:
omc_16 = [ -2.070729e+00 ; -2.176194e+00 ; -1.688456e-01 ];
Tc_16  = [ -1.347076e+02 ; -1.037475e+02 ; 4.904863e+02 ];
omc_error_16 = [ 3.577656e-03 ; 4.448458e-03 ; 8.343757e-03 ];
Tc_error_16  = [ 2.654292e+00 ; 2.109215e+00 ; 1.998393e+00 ];

%-- Image #17:
omc_17 = [ 1.888088e+00 ; 2.242197e+00 ; -1.263844e-01 ];
Tc_17  = [ -1.365326e+02 ; -1.203721e+02 ; 7.290489e+02 ];
omc_error_17 = [ 4.626268e-03 ; 6.067436e-03 ; 1.091933e-02 ];
Tc_error_17  = [ 3.907537e+00 ; 3.086697e+00 ; 2.765494e+00 ];

%-- Image #18:
omc_18 = [ -1.975669e+00 ; -1.518312e+00 ; 6.095539e-01 ];
Tc_18  = [ -1.745087e+02 ; -4.431279e+01 ; 6.290180e+02 ];
omc_error_18 = [ 4.491899e-03 ; 3.552692e-03 ; 6.577345e-03 ];
Tc_error_18  = [ 3.379776e+00 ; 2.676257e+00 ; 1.991038e+00 ];

%-- Image #19:
omc_19 = [ 1.576421e+00 ; 1.834137e+00 ; -2.897675e-01 ];
Tc_19  = [ -1.345193e+02 ; -1.049909e+02 ; 6.661835e+02 ];
omc_error_19 = [ 3.188690e-03 ; 4.691134e-03 ; 6.451881e-03 ];
Tc_error_19  = [ 3.561054e+00 ; 2.821731e+00 ; 2.399594e+00 ];

%-- Image #20:
omc_20 = [ 2.136003e+00 ; 2.158234e+00 ; 7.097479e-01 ];
Tc_20  = [ -1.522027e+02 ; -6.783836e+01 ; 8.317953e+02 ];
omc_error_20 = [ 6.063918e-03 ; 4.324179e-03 ; 9.940520e-03 ];
Tc_error_20  = [ 4.476482e+00 ; 3.544840e+00 ; 3.572509e+00 ];

%-- Image #21:
omc_21 = [ 1.916296e+00 ; 1.945445e+00 ; -4.002410e-01 ];
Tc_21  = [ -1.438133e+02 ; -9.382513e+01 ; 6.312696e+02 ];
omc_error_21 = [ 3.309355e-03 ; 4.497170e-03 ; 7.743212e-03 ];
Tc_error_21  = [ 3.379436e+00 ; 2.673949e+00 ; 2.268617e+00 ];

%-- Image #22:
omc_22 = [ 1.363520e+00 ; 1.684616e+00 ; -1.920795e-01 ];
Tc_22  = [ -1.449447e+02 ; -1.055405e+02 ; 6.818770e+02 ];
omc_error_22 = [ 3.281544e-03 ; 4.804192e-03 ; 5.608273e-03 ];
Tc_error_22  = [ 3.645626e+00 ; 2.893530e+00 ; 2.508344e+00 ];

%-- Image #23:
omc_23 = [ -2.047564e+00 ; -2.070909e+00 ; 3.368733e-01 ];
Tc_23  = [ -1.157616e+02 ; -7.778777e+01 ; 6.361686e+02 ];
omc_error_23 = [ 4.265152e-03 ; 4.456100e-03 ; 8.723142e-03 ];
Tc_error_23  = [ 3.392126e+00 ; 2.680145e+00 ; 2.202719e+00 ];

%-- Image #24:
omc_24 = [ 2.143541e+00 ; 2.192784e+00 ; -2.114458e-01 ];
Tc_24  = [ -1.082955e+02 ; -7.002486e+01 ; 8.683537e+02 ];
omc_error_24 = [ 7.928466e-03 ; 7.729360e-03 ; 1.668359e-02 ];
Tc_error_24  = [ 4.642679e+00 ; 3.658681e+00 ; 3.291118e+00 ];

%-- Image #25:
omc_25 = [ NaN ; NaN ; NaN ];
Tc_25  = [ NaN ; NaN ; NaN ];
omc_error_25 = [ NaN ; NaN ; NaN ];
Tc_error_25  = [ NaN ; NaN ; NaN ];

%-- Image #26:
omc_26 = [ -1.723975e+00 ; -1.748056e+00 ; 1.073986e+00 ];
Tc_26  = [ -1.005513e+02 ; -8.471853e+01 ; 7.611937e+02 ];
omc_error_26 = [ 5.135988e-03 ; 3.727382e-03 ; 6.234918e-03 ];
Tc_error_26  = [ 4.085878e+00 ; 3.221335e+00 ; 2.131053e+00 ];

%-- Image #27:
omc_27 = [ 1.847988e+00 ; 1.754205e+00 ; 2.603474e-01 ];
Tc_27  = [ -1.621678e+02 ; -9.389308e+01 ; 5.902966e+02 ];
omc_error_27 = [ 4.031187e-03 ; 4.149504e-03 ; 6.843036e-03 ];
Tc_error_27  = [ 3.191499e+00 ; 2.523947e+00 ; 2.410031e+00 ];

%-- Image #28:
omc_28 = [ 1.820888e+00 ; 1.718671e+00 ; -1.046240e+00 ];
Tc_28  = [ -1.278134e+02 ; -9.360547e+00 ; 7.297286e+02 ];
omc_error_28 = [ 3.192875e-03 ; 4.609889e-03 ; 6.890216e-03 ];
Tc_error_28  = [ 3.898543e+00 ; 3.086021e+00 ; 2.186247e+00 ];

%-- Image #29:
omc_29 = [ NaN ; NaN ; NaN ];
Tc_29  = [ NaN ; NaN ; NaN ];
omc_error_29 = [ NaN ; NaN ; NaN ];
Tc_error_29  = [ NaN ; NaN ; NaN ];

%-- Image #30:
omc_30 = [ NaN ; NaN ; NaN ];
Tc_30  = [ NaN ; NaN ; NaN ];
omc_error_30 = [ NaN ; NaN ; NaN ];
Tc_error_30  = [ NaN ; NaN ; NaN ];

%-- Image #31:
omc_31 = [ NaN ; NaN ; NaN ];
Tc_31  = [ NaN ; NaN ; NaN ];
omc_error_31 = [ NaN ; NaN ; NaN ];
Tc_error_31  = [ NaN ; NaN ; NaN ];

%-- Image #32:
omc_32 = [ NaN ; NaN ; NaN ];
Tc_32  = [ NaN ; NaN ; NaN ];
omc_error_32 = [ NaN ; NaN ; NaN ];
Tc_error_32  = [ NaN ; NaN ; NaN ];

%-- Image #33:
omc_33 = [ NaN ; NaN ; NaN ];
Tc_33  = [ NaN ; NaN ; NaN ];
omc_error_33 = [ NaN ; NaN ; NaN ];
Tc_error_33  = [ NaN ; NaN ; NaN ];

%-- Image #34:
omc_34 = [ NaN ; NaN ; NaN ];
Tc_34  = [ NaN ; NaN ; NaN ];
omc_error_34 = [ NaN ; NaN ; NaN ];
Tc_error_34  = [ NaN ; NaN ; NaN ];

%-- Image #35:
omc_35 = [ NaN ; NaN ; NaN ];
Tc_35  = [ NaN ; NaN ; NaN ];
omc_error_35 = [ NaN ; NaN ; NaN ];
Tc_error_35  = [ NaN ; NaN ; NaN ];

%-- Image #36:
omc_36 = [ NaN ; NaN ; NaN ];
Tc_36  = [ NaN ; NaN ; NaN ];
omc_error_36 = [ NaN ; NaN ; NaN ];
Tc_error_36  = [ NaN ; NaN ; NaN ];

%-- Image #37:
omc_37 = [ NaN ; NaN ; NaN ];
Tc_37  = [ NaN ; NaN ; NaN ];
omc_error_37 = [ NaN ; NaN ; NaN ];
Tc_error_37  = [ NaN ; NaN ; NaN ];

%-- Image #38:
omc_38 = [ NaN ; NaN ; NaN ];
Tc_38  = [ NaN ; NaN ; NaN ];
omc_error_38 = [ NaN ; NaN ; NaN ];
Tc_error_38  = [ NaN ; NaN ; NaN ];

%-- Image #39:
omc_39 = [ NaN ; NaN ; NaN ];
Tc_39  = [ NaN ; NaN ; NaN ];
omc_error_39 = [ NaN ; NaN ; NaN ];
Tc_error_39  = [ NaN ; NaN ; NaN ];

%-- Image #40:
omc_40 = [ NaN ; NaN ; NaN ];
Tc_40  = [ NaN ; NaN ; NaN ];
omc_error_40 = [ NaN ; NaN ; NaN ];
Tc_error_40  = [ NaN ; NaN ; NaN ];

%-- Image #41:
omc_41 = [ NaN ; NaN ; NaN ];
Tc_41  = [ NaN ; NaN ; NaN ];
omc_error_41 = [ NaN ; NaN ; NaN ];
Tc_error_41  = [ NaN ; NaN ; NaN ];

%-- Image #42:
omc_42 = [ NaN ; NaN ; NaN ];
Tc_42  = [ NaN ; NaN ; NaN ];
omc_error_42 = [ NaN ; NaN ; NaN ];
Tc_error_42  = [ NaN ; NaN ; NaN ];

%-- Image #43:
omc_43 = [ NaN ; NaN ; NaN ];
Tc_43  = [ NaN ; NaN ; NaN ];
omc_error_43 = [ NaN ; NaN ; NaN ];
Tc_error_43  = [ NaN ; NaN ; NaN ];

%-- Image #44:
omc_44 = [ NaN ; NaN ; NaN ];
Tc_44  = [ NaN ; NaN ; NaN ];
omc_error_44 = [ NaN ; NaN ; NaN ];
Tc_error_44  = [ NaN ; NaN ; NaN ];

%-- Image #45:
omc_45 = [ NaN ; NaN ; NaN ];
Tc_45  = [ NaN ; NaN ; NaN ];
omc_error_45 = [ NaN ; NaN ; NaN ];
Tc_error_45  = [ NaN ; NaN ; NaN ];

%-- Image #46:
omc_46 = [ NaN ; NaN ; NaN ];
Tc_46  = [ NaN ; NaN ; NaN ];
omc_error_46 = [ NaN ; NaN ; NaN ];
Tc_error_46  = [ NaN ; NaN ; NaN ];

%-- Image #47:
omc_47 = [ NaN ; NaN ; NaN ];
Tc_47  = [ NaN ; NaN ; NaN ];
omc_error_47 = [ NaN ; NaN ; NaN ];
Tc_error_47  = [ NaN ; NaN ; NaN ];

%-- Image #48:
omc_48 = [ NaN ; NaN ; NaN ];
Tc_48  = [ NaN ; NaN ; NaN ];
omc_error_48 = [ NaN ; NaN ; NaN ];
Tc_error_48  = [ NaN ; NaN ; NaN ];

%-- Image #49:
omc_49 = [ NaN ; NaN ; NaN ];
Tc_49  = [ NaN ; NaN ; NaN ];
omc_error_49 = [ NaN ; NaN ; NaN ];
Tc_error_49  = [ NaN ; NaN ; NaN ];

%-- Image #50:
omc_50 = [ NaN ; NaN ; NaN ];
Tc_50  = [ NaN ; NaN ; NaN ];
omc_error_50 = [ NaN ; NaN ; NaN ];
Tc_error_50  = [ NaN ; NaN ; NaN ];

%-- Image #51:
omc_51 = [ NaN ; NaN ; NaN ];
Tc_51  = [ NaN ; NaN ; NaN ];
omc_error_51 = [ NaN ; NaN ; NaN ];
Tc_error_51  = [ NaN ; NaN ; NaN ];

%-- Image #52:
omc_52 = [ NaN ; NaN ; NaN ];
Tc_52  = [ NaN ; NaN ; NaN ];
omc_error_52 = [ NaN ; NaN ; NaN ];
Tc_error_52  = [ NaN ; NaN ; NaN ];

%-- Image #53:
omc_53 = [ NaN ; NaN ; NaN ];
Tc_53  = [ NaN ; NaN ; NaN ];
omc_error_53 = [ NaN ; NaN ; NaN ];
Tc_error_53  = [ NaN ; NaN ; NaN ];

%-- Image #54:
omc_54 = [ NaN ; NaN ; NaN ];
Tc_54  = [ NaN ; NaN ; NaN ];
omc_error_54 = [ NaN ; NaN ; NaN ];
Tc_error_54  = [ NaN ; NaN ; NaN ];

%-- Image #55:
omc_55 = [ NaN ; NaN ; NaN ];
Tc_55  = [ NaN ; NaN ; NaN ];
omc_error_55 = [ NaN ; NaN ; NaN ];
Tc_error_55  = [ NaN ; NaN ; NaN ];

%-- Image #56:
omc_56 = [ NaN ; NaN ; NaN ];
Tc_56  = [ NaN ; NaN ; NaN ];
omc_error_56 = [ NaN ; NaN ; NaN ];
Tc_error_56  = [ NaN ; NaN ; NaN ];

%-- Image #57:
omc_57 = [ NaN ; NaN ; NaN ];
Tc_57  = [ NaN ; NaN ; NaN ];
omc_error_57 = [ NaN ; NaN ; NaN ];
Tc_error_57  = [ NaN ; NaN ; NaN ];

%-- Image #58:
omc_58 = [ NaN ; NaN ; NaN ];
Tc_58  = [ NaN ; NaN ; NaN ];
omc_error_58 = [ NaN ; NaN ; NaN ];
Tc_error_58  = [ NaN ; NaN ; NaN ];

%-- Image #59:
omc_59 = [ NaN ; NaN ; NaN ];
Tc_59  = [ NaN ; NaN ; NaN ];
omc_error_59 = [ NaN ; NaN ; NaN ];
Tc_error_59  = [ NaN ; NaN ; NaN ];

%-- Image #60:
omc_60 = [ NaN ; NaN ; NaN ];
Tc_60  = [ NaN ; NaN ; NaN ];
omc_error_60 = [ NaN ; NaN ; NaN ];
Tc_error_60  = [ NaN ; NaN ; NaN ];

%-- Image #61:
omc_61 = [ NaN ; NaN ; NaN ];
Tc_61  = [ NaN ; NaN ; NaN ];
omc_error_61 = [ NaN ; NaN ; NaN ];
Tc_error_61  = [ NaN ; NaN ; NaN ];

%-- Image #62:
omc_62 = [ NaN ; NaN ; NaN ];
Tc_62  = [ NaN ; NaN ; NaN ];
omc_error_62 = [ NaN ; NaN ; NaN ];
Tc_error_62  = [ NaN ; NaN ; NaN ];

%-- Image #63:
omc_63 = [ NaN ; NaN ; NaN ];
Tc_63  = [ NaN ; NaN ; NaN ];
omc_error_63 = [ NaN ; NaN ; NaN ];
Tc_error_63  = [ NaN ; NaN ; NaN ];

%-- Image #64:
omc_64 = [ NaN ; NaN ; NaN ];
Tc_64  = [ NaN ; NaN ; NaN ];
omc_error_64 = [ NaN ; NaN ; NaN ];
Tc_error_64  = [ NaN ; NaN ; NaN ];

%-- Image #65:
omc_65 = [ NaN ; NaN ; NaN ];
Tc_65  = [ NaN ; NaN ; NaN ];
omc_error_65 = [ NaN ; NaN ; NaN ];
Tc_error_65  = [ NaN ; NaN ; NaN ];

%-- Image #66:
omc_66 = [ NaN ; NaN ; NaN ];
Tc_66  = [ NaN ; NaN ; NaN ];
omc_error_66 = [ NaN ; NaN ; NaN ];
Tc_error_66  = [ NaN ; NaN ; NaN ];

%-- Image #67:
omc_67 = [ NaN ; NaN ; NaN ];
Tc_67  = [ NaN ; NaN ; NaN ];
omc_error_67 = [ NaN ; NaN ; NaN ];
Tc_error_67  = [ NaN ; NaN ; NaN ];

%-- Image #68:
omc_68 = [ NaN ; NaN ; NaN ];
Tc_68  = [ NaN ; NaN ; NaN ];
omc_error_68 = [ NaN ; NaN ; NaN ];
Tc_error_68  = [ NaN ; NaN ; NaN ];

%-- Image #69:
omc_69 = [ NaN ; NaN ; NaN ];
Tc_69  = [ NaN ; NaN ; NaN ];
omc_error_69 = [ NaN ; NaN ; NaN ];
Tc_error_69  = [ NaN ; NaN ; NaN ];

%-- Image #70:
omc_70 = [ NaN ; NaN ; NaN ];
Tc_70  = [ NaN ; NaN ; NaN ];
omc_error_70 = [ NaN ; NaN ; NaN ];
Tc_error_70  = [ NaN ; NaN ; NaN ];

%-- Image #71:
omc_71 = [ NaN ; NaN ; NaN ];
Tc_71  = [ NaN ; NaN ; NaN ];
omc_error_71 = [ NaN ; NaN ; NaN ];
Tc_error_71  = [ NaN ; NaN ; NaN ];

%-- Image #72:
omc_72 = [ NaN ; NaN ; NaN ];
Tc_72  = [ NaN ; NaN ; NaN ];
omc_error_72 = [ NaN ; NaN ; NaN ];
Tc_error_72  = [ NaN ; NaN ; NaN ];

%-- Image #73:
omc_73 = [ NaN ; NaN ; NaN ];
Tc_73  = [ NaN ; NaN ; NaN ];
omc_error_73 = [ NaN ; NaN ; NaN ];
Tc_error_73  = [ NaN ; NaN ; NaN ];

%-- Image #74:
omc_74 = [ NaN ; NaN ; NaN ];
Tc_74  = [ NaN ; NaN ; NaN ];
omc_error_74 = [ NaN ; NaN ; NaN ];
Tc_error_74  = [ NaN ; NaN ; NaN ];

%-- Image #75:
omc_75 = [ NaN ; NaN ; NaN ];
Tc_75  = [ NaN ; NaN ; NaN ];
omc_error_75 = [ NaN ; NaN ; NaN ];
Tc_error_75  = [ NaN ; NaN ; NaN ];

%-- Image #76:
omc_76 = [ NaN ; NaN ; NaN ];
Tc_76  = [ NaN ; NaN ; NaN ];
omc_error_76 = [ NaN ; NaN ; NaN ];
Tc_error_76  = [ NaN ; NaN ; NaN ];

%-- Image #77:
omc_77 = [ NaN ; NaN ; NaN ];
Tc_77  = [ NaN ; NaN ; NaN ];
omc_error_77 = [ NaN ; NaN ; NaN ];
Tc_error_77  = [ NaN ; NaN ; NaN ];

%-- Image #78:
omc_78 = [ NaN ; NaN ; NaN ];
Tc_78  = [ NaN ; NaN ; NaN ];
omc_error_78 = [ NaN ; NaN ; NaN ];
Tc_error_78  = [ NaN ; NaN ; NaN ];

%-- Image #79:
omc_79 = [ NaN ; NaN ; NaN ];
Tc_79  = [ NaN ; NaN ; NaN ];
omc_error_79 = [ NaN ; NaN ; NaN ];
Tc_error_79  = [ NaN ; NaN ; NaN ];

%-- Image #80:
omc_80 = [ NaN ; NaN ; NaN ];
Tc_80  = [ NaN ; NaN ; NaN ];
omc_error_80 = [ NaN ; NaN ; NaN ];
Tc_error_80  = [ NaN ; NaN ; NaN ];

%-- Image #81:
omc_81 = [ NaN ; NaN ; NaN ];
Tc_81  = [ NaN ; NaN ; NaN ];
omc_error_81 = [ NaN ; NaN ; NaN ];
Tc_error_81  = [ NaN ; NaN ; NaN ];

%-- Image #82:
omc_82 = [ NaN ; NaN ; NaN ];
Tc_82  = [ NaN ; NaN ; NaN ];
omc_error_82 = [ NaN ; NaN ; NaN ];
Tc_error_82  = [ NaN ; NaN ; NaN ];

%-- Image #83:
omc_83 = [ NaN ; NaN ; NaN ];
Tc_83  = [ NaN ; NaN ; NaN ];
omc_error_83 = [ NaN ; NaN ; NaN ];
Tc_error_83  = [ NaN ; NaN ; NaN ];

%-- Image #84:
omc_84 = [ NaN ; NaN ; NaN ];
Tc_84  = [ NaN ; NaN ; NaN ];
omc_error_84 = [ NaN ; NaN ; NaN ];
Tc_error_84  = [ NaN ; NaN ; NaN ];

%-- Image #85:
omc_85 = [ NaN ; NaN ; NaN ];
Tc_85  = [ NaN ; NaN ; NaN ];
omc_error_85 = [ NaN ; NaN ; NaN ];
Tc_error_85  = [ NaN ; NaN ; NaN ];

%-- Image #86:
omc_86 = [ NaN ; NaN ; NaN ];
Tc_86  = [ NaN ; NaN ; NaN ];
omc_error_86 = [ NaN ; NaN ; NaN ];
Tc_error_86  = [ NaN ; NaN ; NaN ];

%-- Image #87:
omc_87 = [ NaN ; NaN ; NaN ];
Tc_87  = [ NaN ; NaN ; NaN ];
omc_error_87 = [ NaN ; NaN ; NaN ];
Tc_error_87  = [ NaN ; NaN ; NaN ];

%-- Image #88:
omc_88 = [ NaN ; NaN ; NaN ];
Tc_88  = [ NaN ; NaN ; NaN ];
omc_error_88 = [ NaN ; NaN ; NaN ];
Tc_error_88  = [ NaN ; NaN ; NaN ];

%-- Image #89:
omc_89 = [ NaN ; NaN ; NaN ];
Tc_89  = [ NaN ; NaN ; NaN ];
omc_error_89 = [ NaN ; NaN ; NaN ];
Tc_error_89  = [ NaN ; NaN ; NaN ];

%-- Image #90:
omc_90 = [ NaN ; NaN ; NaN ];
Tc_90  = [ NaN ; NaN ; NaN ];
omc_error_90 = [ NaN ; NaN ; NaN ];
Tc_error_90  = [ NaN ; NaN ; NaN ];

