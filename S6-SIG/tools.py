from numpy import *
from matplotlib.pyplot import *
from numpy.fft import *

def specdet1(signal,N):
    y=fft(signal,N);
    Py=abs(y);
    n_vect = arange(0,4*N)
    dsp=zeros(len(n_vect))
    
    #périodisation du spectre sur [-2,2]
    for n in range(4):
        dsp[n*N:(n+1)*N]=Py
    
    # affichage
    N_dsp=len(dsp);
    f=4*np.arange(-N_dsp/2,N_dsp/2)/N_dsp;
    plot(f,dsp);
    xlabel('frequences normalisees f=F/Fe')
    ylabel('spectre d''amplitude')
    ylim([0,int(max(dsp))+1])
