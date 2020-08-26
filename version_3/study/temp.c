int function(void)
{
    int ImageHeight = 1080;
    int ImageWidth = 1920;
    double MinRe = -2.0;
    double MaxRe = 1.0;
    double MinIm = -1.2;

    double MaxIm = MinIm + (MaxRe - MinRe) * ImageHeight / ImageWidth;

    double Re_factor = (MaxRe - MinRe) / (ImageWidth - 1);
    double Im_factor = (MaxIm-MinIm)/(ImageHeight-1);

    unsigned MaxIterations = 30;

    for(unsigned y=0; y < ImageHeight; ++y)
    {
        double c_im = MaxIm - y*Im_factor;
        for(unsigned x=0; x<ImageWidth; ++x)
        {   
            double c_re = MinRe + x*Re_factor;

            double Z_re = c_re;
            double Z_im = c_im;

            int  isInside = 1;
            for(unsigned n=0; n<MaxIterations; ++n)
            {
                double Z_re2 = Z_re*Z_re, Z_im2 = Z_im*Z_im;
                if(Z_re2 + Z_im2 > 4)
                {
                    isInside = 0;
                    break;
                }
                Z_im = 2*Z_re*Z_im + c_im;
                Z_re = Z_re2 - Z_im2 + c_re;
            }
            if(isInside) { putpixel(x, y); }
        }
    }
}