% Intrinsic and Extrinsic Camera Parameters
%
% This script file can be directly executed under Matlab to recover the camera intrinsic and extrinsic parameters.
% IMPORTANT: This file contains neither the structure of the calibration objects nor the image coordinates of the calibration points.
%            All those complementary variables are saved in the complete matlab data file Calib_Results.mat.
% For more information regarding the calibration model visit http://www.vision.caltech.edu/bouguetj/calib_doc/


%-- Focal length:
fc = [ 1337.358683662614600 ; 1334.576723182819000 ];

%-- Principal point:
cc = [ 672.175351705978640 ; 512.795802890443040 ];

%-- Skew coefficient:
alpha_c = 0.000000000000000;

%-- Distortion coefficients:
kc = [ -0.123981522403811 ; 0.118045849629442 ; 0.003176332295977 ; 0.001686772087973 ; 0.000000000000000 ];

%-- Focal length uncertainty:
fc_error = [ 3.996424838904266 ; 3.830904001558330 ];

%-- Principal point uncertainty:
cc_error = [ 6.071214623130283 ; 4.849903632471124 ];

%-- Skew coefficient uncertainty:
alpha_c_error = 0.000000000000000;

%-- Distortion coefficients uncertainty:
kc_error = [ 0.016731287522627 ; 0.122749944977730 ; 0.000918050105095 ; 0.001112952623379 ; 0.000000000000000 ];

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
omc_1 = [ -2.477396e+00 ; -1.639604e+00 ; 5.776711e-01 ];
Tc_1  = [ -1.398075e+02 ; 1.118266e+01 ; 9.222253e+02 ];
omc_error_1 = [ 5.299897e-03 ; 3.372173e-03 ; 9.418421e-03 ];
Tc_error_1  = [ 4.188905e+00 ; 3.351895e+00 ; 2.767648e+00 ];

%-- Image #2:
omc_2 = [ -2.108910e+00 ; -2.258807e+00 ; 1.188712e-01 ];
Tc_2  = [ -1.640015e+02 ; -9.844632e+01 ; 5.939511e+02 ];
omc_error_2 = [ 3.993819e-03 ; 4.229743e-03 ; 8.817706e-03 ];
Tc_error_2  = [ 2.706328e+00 ; 2.186025e+00 ; 2.187653e+00 ];

%-- Image #3:
omc_3 = [ 1.826434e+00 ; 1.723907e+00 ; -1.105728e+00 ];
Tc_3  = [ -1.227284e+02 ; -3.340571e+01 ; 7.047499e+02 ];
omc_error_3 = [ 2.749839e-03 ; 4.066481e-03 ; 5.855542e-03 ];
Tc_error_3  = [ 3.206355e+00 ; 2.568491e+00 ; 1.951033e+00 ];

%-- Image #4:
omc_4 = [ -2.331656e+00 ; -1.389297e+00 ; 1.063695e+00 ];
Tc_4  = [ -1.283856e+02 ; 2.360281e+01 ; 9.785064e+02 ];
omc_error_4 = [ 5.036888e-03 ; 2.498209e-03 ; 6.651476e-03 ];
Tc_error_4  = [ 4.456511e+00 ; 3.557534e+00 ; 2.730942e+00 ];

%-- Image #5:
omc_5 = [ -1.911641e+00 ; -2.076479e+00 ; 8.482931e-01 ];
Tc_5  = [ -4.003024e+01 ; -4.149002e+01 ; 9.515122e+02 ];
omc_error_5 = [ 4.383819e-03 ; 3.874076e-03 ; 7.332526e-03 ];
Tc_error_5  = [ 4.310893e+00 ; 3.450091e+00 ; 2.731231e+00 ];

%-- Image #6:
omc_6 = [ -1.772834e+00 ; -2.263414e+00 ; 5.001784e-01 ];
Tc_6  = [ -1.384751e+02 ; -9.173812e+01 ; 8.607619e+02 ];
omc_error_6 = [ 3.941320e-03 ; 4.581886e-03 ; 7.784454e-03 ];
Tc_error_6  = [ 3.906904e+00 ; 3.147503e+00 ; 2.725446e+00 ];

%-- Image #7:
omc_7 = [ 1.846996e+00 ; 1.929757e+00 ; -6.525545e-01 ];
Tc_7  = [ -1.371109e+02 ; -6.716836e+01 ; 6.909031e+02 ];
omc_error_7 = [ 2.666178e-03 ; 3.952231e-03 ; 6.351188e-03 ];
Tc_error_7  = [ 3.136561e+00 ; 2.519232e+00 ; 2.153829e+00 ];

%-- Image #8:
omc_8 = [ 1.992089e+00 ; 2.064007e+00 ; -2.104604e-02 ];
Tc_8  = [ -1.213125e+02 ; -5.521539e+00 ; 9.179553e+02 ];
omc_error_8 = [ 5.875712e-03 ; 5.831014e-03 ; 1.171447e-02 ];
Tc_error_8  = [ 4.172897e+00 ; 3.353862e+00 ; 3.497827e+00 ];

%-- Image #9:
omc_9 = [ 2.026184e+00 ; 2.020067e+00 ; 1.265120e-01 ];
Tc_9  = [ -1.262410e+02 ; -6.467652e+01 ; 8.758696e+02 ];
omc_error_9 = [ 5.144206e-03 ; 5.140711e-03 ; 1.010755e-02 ];
Tc_error_9  = [ 3.986479e+00 ; 3.195114e+00 ; 3.329534e+00 ];

%-- Image #10:
omc_10 = [ 1.786074e+00 ; 1.690635e+00 ; 4.413728e-01 ];
Tc_10  = [ -1.662276e+02 ; -9.765323e+01 ; 5.796100e+02 ];
omc_error_10 = [ 3.654525e-03 ; 3.501195e-03 ; 5.454192e-03 ];
Tc_error_10  = [ 2.677748e+00 ; 2.142993e+00 ; 2.273319e+00 ];

%-- Image #11:
omc_11 = [ 2.435154e+00 ; 1.519570e+00 ; -1.028556e+00 ];
Tc_11  = [ -1.453240e+02 ; 1.568807e+00 ; 7.919096e+02 ];
omc_error_11 = [ 3.208010e-03 ; 3.705468e-03 ; 7.231325e-03 ];
Tc_error_11  = [ 3.608797e+00 ; 2.883662e+00 ; 2.247350e+00 ];

%-- Image #12:
omc_12 = [ 1.564541e+00 ; 1.997262e+00 ; 3.874345e-01 ];
Tc_12  = [ -1.234738e+02 ; -6.545118e+01 ; 7.358507e+02 ];
omc_error_12 = [ 3.693807e-03 ; 3.981198e-03 ; 6.000054e-03 ];
Tc_error_12  = [ 3.348475e+00 ; 2.700131e+00 ; 2.755968e+00 ];

%-- Image #13:
omc_13 = [ -1.122752e+00 ; -2.351361e+00 ; 6.630951e-01 ];
Tc_13  = [ -6.296956e+01 ; -1.766367e+02 ; 8.452307e+02 ];
omc_error_13 = [ 3.365516e-03 ; 4.524426e-03 ; 5.809630e-03 ];
Tc_error_13  = [ 3.864436e+00 ; 3.085399e+00 ; 2.671578e+00 ];

%-- Image #14:
omc_14 = [ -1.997637e+00 ; -2.145183e+00 ; 4.763943e-01 ];
Tc_14  = [ -1.195922e+02 ; -1.148907e+02 ; 6.751085e+02 ];
omc_error_14 = [ 3.913117e-03 ; 3.577974e-03 ; 7.516026e-03 ];
Tc_error_14  = [ 3.076047e+00 ; 2.455268e+00 ; 2.156177e+00 ];

%-- Image #15:
omc_15 = [ 1.957646e+00 ; 2.193944e+00 ; -4.091652e-01 ];
Tc_15  = [ -1.373149e+02 ; -8.474232e+01 ; 6.521639e+02 ];
omc_error_15 = [ 3.205031e-03 ; 4.203539e-03 ; 7.728443e-03 ];
Tc_error_15  = [ 2.958312e+00 ; 2.376426e+00 ; 2.170960e+00 ];

%-- Image #16:
omc_16 = [ -2.068442e+00 ; -2.172855e+00 ; -1.676958e-01 ];
Tc_16  = [ -1.331090e+02 ; -1.051619e+02 ; 4.892090e+02 ];
omc_error_16 = [ 3.087640e-03 ; 3.837671e-03 ; 7.129792e-03 ];
Tc_error_16  = [ 2.250904e+00 ; 1.812668e+00 ; 1.845572e+00 ];

%-- Image #17:
omc_17 = [ 1.890860e+00 ; 2.245503e+00 ; -1.283251e-01 ];
Tc_17  = [ -1.342006e+02 ; -1.225010e+02 ; 7.273108e+02 ];
omc_error_17 = [ 4.036567e-03 ; 5.274690e-03 ; 9.384714e-03 ];
Tc_error_17  = [ 3.313418e+00 ; 2.651795e+00 ; 2.580595e+00 ];

%-- Image #18:
omc_18 = [ NaN ; NaN ; NaN ];
Tc_18  = [ NaN ; NaN ; NaN ];
omc_error_18 = [ NaN ; NaN ; NaN ];
Tc_error_18  = [ NaN ; NaN ; NaN ];

%-- Image #19:
omc_19 = [ 1.578601e+00 ; 1.835826e+00 ; -2.886506e-01 ];
Tc_19  = [ -1.324764e+02 ; -1.069299e+02 ; 6.642021e+02 ];
omc_error_19 = [ 2.782643e-03 ; 4.053972e-03 ; 5.463574e-03 ];
Tc_error_19  = [ 3.018364e+00 ; 2.422610e+00 ; 2.243877e+00 ];

%-- Image #20:
omc_20 = [ 2.139655e+00 ; 2.158688e+00 ; 7.147294e-01 ];
Tc_20  = [ -1.492840e+02 ; -7.020475e+01 ; 8.283384e+02 ];
omc_error_20 = [ 5.257538e-03 ; 3.740004e-03 ; 8.552153e-03 ];
Tc_error_20  = [ 3.791322e+00 ; 3.041130e+00 ; 3.312139e+00 ];

%-- Image #21:
omc_21 = [ 1.918039e+00 ; 1.948325e+00 ; -4.022887e-01 ];
Tc_21  = [ -1.417542e+02 ; -9.562595e+01 ; 6.297399e+02 ];
omc_error_21 = [ 2.867461e-03 ; 3.889100e-03 ; 6.579701e-03 ];
Tc_error_21  = [ 2.866019e+00 ; 2.295988e+00 ; 2.115242e+00 ];

%-- Image #22:
omc_22 = [ 1.366047e+00 ; 1.687765e+00 ; -1.921643e-01 ];
Tc_22  = [ -1.427496e+02 ; -1.075376e+02 ; 6.801072e+02 ];
omc_error_22 = [ 2.858660e-03 ; 4.132921e-03 ; 4.753174e-03 ];
Tc_error_22  = [ 3.091083e+00 ; 2.485636e+00 ; 2.344247e+00 ];

%-- Image #23:
omc_23 = [ -2.044780e+00 ; -2.068781e+00 ; 3.356374e-01 ];
Tc_23  = [ -1.137185e+02 ; -7.963530e+01 ; 6.344625e+02 ];
omc_error_23 = [ 3.651419e-03 ; 3.827389e-03 ; 7.483833e-03 ];
Tc_error_23  = [ 2.875633e+00 ; 2.302493e+00 ; 2.057559e+00 ];

%-- Image #24:
omc_24 = [ 2.144178e+00 ; 2.193493e+00 ; -2.209206e-01 ];
Tc_24  = [ -1.054691e+02 ; -7.247734e+01 ; 8.670781e+02 ];
omc_error_24 = [ 6.827547e-03 ; 6.648658e-03 ; 1.432683e-02 ];
Tc_error_24  = [ 3.940809e+00 ; 3.148654e+00 ; 3.054518e+00 ];

%-- Image #25:
omc_25 = [ NaN ; NaN ; NaN ];
Tc_25  = [ NaN ; NaN ; NaN ];
omc_error_25 = [ NaN ; NaN ; NaN ];
Tc_error_25  = [ NaN ; NaN ; NaN ];

%-- Image #26:
omc_26 = [ -1.719709e+00 ; -1.747084e+00 ; 1.073648e+00 ];
Tc_26  = [ -9.806847e+01 ; -8.690632e+01 ; 7.597984e+02 ];
omc_error_26 = [ 4.410361e-03 ; 3.160318e-03 ; 5.292171e-03 ];
Tc_error_26  = [ 3.465253e+00 ; 2.770013e+00 ; 2.001073e+00 ];

%-- Image #27:
omc_27 = [ 1.851669e+00 ; 1.756854e+00 ; 2.589553e-01 ];
Tc_27  = [ -1.603005e+02 ; -9.563290e+01 ; 5.890266e+02 ];
omc_error_27 = [ 3.545659e-03 ; 3.594423e-03 ; 5.819650e-03 ];
Tc_error_27  = [ 2.705753e+00 ; 2.168419e+00 ; 2.237349e+00 ];

%-- Image #28:
omc_28 = [ 1.821243e+00 ; 1.722106e+00 ; -1.048949e+00 ];
Tc_28  = [ -1.254045e+02 ; -1.141169e+01 ; 7.281896e+02 ];
omc_error_28 = [ 2.729695e-03 ; 3.990964e-03 ; 5.848625e-03 ];
Tc_error_28  = [ 3.306819e+00 ; 2.653022e+00 ; 2.042843e+00 ];

%-- Image #29:
omc_29 = [ NaN ; NaN ; NaN ];
Tc_29  = [ NaN ; NaN ; NaN ];
omc_error_29 = [ NaN ; NaN ; NaN ];
Tc_error_29  = [ NaN ; NaN ; NaN ];

%-- Image #30:
omc_30 = [ -2.152691e+00 ; -2.230567e+00 ; 3.265210e-01 ];
Tc_30  = [ -1.515041e+02 ; -1.081544e+02 ; 5.259927e+02 ];
omc_error_30 = [ 3.677282e-03 ; 3.197072e-03 ; 7.360607e-03 ];
Tc_error_30  = [ 2.398875e+00 ; 1.924210e+00 ; 1.882707e+00 ];

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

