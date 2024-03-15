from modsim import *
import matplotlib.pyplot as plt

telu = State(bandung=20, surabaya=12, jakarta=4)
def step(i, prob_bandung, prob_surabaya, prob_jakarta):
    if i % 2 == 0:
        telu.bandung -= 1
        if flip(prob_surabaya):
            telu.surabaya += 1

        if flip(prob_jakarta):
            telu.jakarta += 1
    elif i % 3 == 0:
        telu.surabaya -= 1
        if flip(prob_bandung):
            telu.bandung += 1

        if flip(prob_jakarta):
            telu.jakarta += 1
    elif i % 5 == 0:
        telu.jakarta -= 1
        if flip(prob_bandung):
            telu.bandung += 1

        if flip(prob_surabaya):
            telu.surabaya += 1

def run_simulation(prob_bandung, prob_surabaya, prob_jakarta, minutes):
    result_surabaya = TimeSeries()
    result_surabaya[0] = telu.surabaya
    
    for i in range(minutes):
        step(i, prob_bandung, prob_surabaya, prob_jakarta)
        result_surabaya[i+1] = telu.surabaya
        
    result_surabaya.plot(label='Surabaya')
    decorate(
        title='Helikopter telu University Surabaya',
        xlabel='Time step (min)',
        ylabel='Jumlah helikopter yang berada di Surabaya'
    )
    plt.show()

run_simulation(0.5, 0.3, 0.2, 480)