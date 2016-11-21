#!/usr/bin/env python
# -*- coding: utf-8 -*-

import numpy as np
import sys


DECIMAL = 4


def forward(start, transition, observation, end):
    S, N = observation.shape
    p = np.empty((N, S), dtype=float)
    # Initialization
    # for s in range(0, S):
    #     p[0][s] = start[s] * observation[s][0]
    p[0] = start * observation.T[0]
    # Recursive
    for n in range(1, N):
        for s in range(0, S):
            # p[n][s] = np.sum([p[n - 1][_s] * transition[_s][s] for _s in range(0, S)]) * observation[s][n]
            p[n][s] = np.dot(p[n - 1], transition.T[s]) * observation[s][n]
    # Termination
    # final = np.sum([p[N - 1][s] * end[s] for s in range(0, S)])
    final = np.dot(p[N - 1], end)
    return p, final


def backward(end, transition, observation, start):
    S, N = observation.shape
    p = np.empty((N, S), dtype=float)
    # Initialization
    p[N - 1] = end
    # Recursive
    for n in reversed(range(0, N - 1)):
        for s in range(0, S):
            # p[n][s] = np.sum([transition[s][_s] * observation[_s][n + 1] * p[n + 1][_s] for _s in range(0, S)])
            p[n][s] = np.sum(transition[s] * observation.T[n + 1] * p[n + 1])
    # Termination
    # initial = np.sum([start[s] * observation[s][0] * p[0][s] for s in range(0, S)])
    initial = np.sum(start * observation.T[0] * p[0])
    return p, initial


def calc_2_latent_p(n, j, k, forward_p, backward_p, start, transition, end, observation, echo=True):
    state1 = state2 = None
    N = observation.shape[1]
    if n - 1 < 0:
        state1 = 'S_in'
        fp = 1.0
        tr = start[j]
        ob = observation[k][n]
        bp = backward_p[n][k]
    elif n >= N:
        state2 = 'S_fin'
        fp = forward_p[n - 1][j]
        tr = end[j]
        ob = 1.0
        bp = 1.0
    else:
        fp = forward_p[n - 1][j]
        tr = transition[j][k]
        ob = observation[k][n]
        bp = backward_p[n][k]
    p = fp * tr * ob * bp
    if echo:
        state1 = state1 if state1 else ('Mother' if j == 0 else ('Father' if j == 1 else 'Undefined'))
        state2 = state2 if state2 else ('Mother' if k == 0 else ('Father' if k == 1 else 'Undefined'))
        print("P(z%d=%s, z%d=%s, X=<A,S,H>|lmd)" % (n, state1, n + 1, state2))
        print("= fp: %.4f * tr: %.4f * ob: %.4f * bp: %.4f" % (fp, tr, ob, bp))
        print("= %f =~ %.4f" % (p, np.around(p, DECIMAL)))
    return np.around(p, DECIMAL)


def calc_1_latent_p(n, j, forward_p, backward_p, initial, final, echo=True):
    state = None
    N = forward_p.shape[0]
    if n < 0:
        state = 'S_in'
        fp = 1.0
        bp = initial
    elif n >= N:
        state = 'S_fin'
        fp = final
        bp = 1.0
    else:
        fp = forward_p[n][j]
        bp = backward_p[n][j]
    p = fp * bp
    if echo:
        state = state if state else ('Mother' if j == 0 else ('Father' if j == 1 else 'Undefined'))
        print("P(z%d=%s, X=<A,S,H>|lmd)" % (n + 1, state))
        print("= fp: %.4f * bp: %.4f" % (fp, bp))
        print("= %f =~ %.4f" % (p, np.around(p, DECIMAL)))
    return np.around(p, DECIMAL)


def main(argv):
    """
    states = ['Mother', 'Father']
    observations = ['Allowance', 'Study', 'Hobby']
    start_probability = {'Mother': 0.5, 'Father': 0.5}
    transition_probability = {
        'Mother': {'Mother': 0.45, 'Father': 0.15},
        'Father': {'Mother': 0.05, 'Father': 0.45}
    }
    observation_probability = {
        'Mother': {'Allowance': 0.25, 'Study': 0.50,'Hobby': 0.25},
        'Father': {'Allowance': 0.30, 'Study': 0.15,'Hobby': 0.55}
    }
    end_probability = {'Mother': 0.4, 'Father': 0.5}
    """

    start = np.array([0.55, 0.45])            # In -> M, In -> F
    transition = np.array([
        [0.3, 0.15],                       # M -> M, M -> F
        [0.05, 0.45]                        # F -> M, F -> F
    ])
    observation = np.array([
        [0.25, 0.50, 0.25],                 # M:A, M:S, M,H
        [0.30, 0.30, 0.40]                  # F:A, F:S, F:H
    ])
    end = np.array([0.55, 0.5])              # M -> Fin, F -> Fin

    # 1. E-step

    forward_p, final = forward(start, transition, observation, end)
    backward_p, initial = backward(end, transition, observation, start)

    forward_p = np.around(forward_p, DECIMAL)
    backward_p = np.around(backward_p, DECIMAL)
    initial = np.around(initial, DECIMAL)
    final = np.around(final, DECIMAL)

    print("forward probability")
    print(forward_p.T)
    print("backward probability")
    print(backward_p.T)
    print("initial, forward * backward, final")
    print(initial, np.around(np.sum(forward_p * backward_p, axis=1), DECIMAL), final)

    if initial != final:
        raise Exception('Calculation Error.')
    likelihood = initial

    print("================")

    xi_mm1 = calc_2_latent_p(1, 0, 0, forward_p, backward_p, start, transition, end, observation) / likelihood
    xi_mf1 = calc_2_latent_p(1, 0, 1, forward_p, backward_p, start, transition, end, observation) / likelihood
    xi_fm1 = calc_2_latent_p(1, 1, 0, forward_p, backward_p, start, transition, end, observation) / likelihood
    xi_ff1 = calc_2_latent_p(1, 1, 1, forward_p, backward_p, start, transition, end, observation) / likelihood

    print('---')

    xi_mm2 = calc_2_latent_p(2, 0, 0, forward_p, backward_p, start, transition, end, observation) / likelihood
    xi_mf2 = calc_2_latent_p(2, 0, 1, forward_p, backward_p, start, transition, end, observation) / likelihood
    xi_fm2 = calc_2_latent_p(2, 1, 0, forward_p, backward_p, start, transition, end, observation) / likelihood
    xi_ff2 = calc_2_latent_p(2, 1, 1, forward_p, backward_p, start, transition, end, observation) / likelihood

    print('---')

    xi_mfin = calc_2_latent_p(3, 0, -1, forward_p, backward_p, start, transition, end, observation) / likelihood
    xi_ffin = calc_2_latent_p(3, 1, -1, forward_p, backward_p, start, transition, end, observation) / likelihood

    print("================")

    gm_m1 = calc_1_latent_p(0, 0, forward_p, backward_p, initial, final) / likelihood
    gm_f1 = calc_1_latent_p(0, 1, forward_p, backward_p, initial, final) / likelihood

    print('---')

    gm_m2 = calc_1_latent_p(1, 0, forward_p, backward_p, initial, final) / likelihood
    gm_f2 = calc_1_latent_p(1, 1, forward_p, backward_p, initial, final) / likelihood

    print('---')

    gm_m3 = calc_1_latent_p(2, 0, forward_p, backward_p, initial, final) / likelihood
    gm_f3 = calc_1_latent_p(2, 1, forward_p, backward_p, initial, final) / likelihood

    print("================")

    # 2. M-step

    xi_mm = xi_mm1 + xi_mm2
    xi_mf = xi_mf1 + xi_mf2
    xi_fm = xi_fm1 + xi_fm2
    xi_ff = xi_ff1 + xi_ff2

    print("gamma_Mother(1) = %f =~ = %.4f" % (gm_m1, np.around(gm_m1, DECIMAL)))
    print("gamma_Father(1) = %f =~ = %.4f" % (gm_f1, np.around(gm_f1, DECIMAL)))
    print("xi_Mother,Mother = %f =~ = %.4f" % (xi_mm, np.around(xi_mm, DECIMAL)))
    print("xi_Mother,Father = %f =~ = %.4f" % (xi_mf, np.around(xi_mf, DECIMAL)))
    print("xi_Mother,fin = %f =~ = %.4f" % (xi_mfin, np.around(xi_mfin, DECIMAL)))
    print("xi_Father,Mother = %f =~ = %.4f" % (xi_fm, np.around(xi_fm, DECIMAL)))
    print("xi_Father,Father = %f =~ = %.4f" % (xi_ff, np.around(xi_ff, DECIMAL)))
    print("xi_Father,fin = %f =~ = %.4f" % (xi_ffin, np.around(xi_ffin, DECIMAL)))

    print("---")

    new_start = np.around(np.array([gm_m1 / (gm_m1 + gm_f1), gm_f1 / (gm_m1 + gm_f1), 0]), DECIMAL)
    print("new start transition probability\n", new_start)
    new_transition = np.around(np.array([
        [xi_mm / (xi_mm + xi_mf + xi_mfin), xi_mf / (xi_mm + xi_mf + xi_mfin), xi_mfin / (xi_mm + xi_mf + xi_mfin)],
        [xi_fm / (xi_fm + xi_ff + xi_ffin), xi_ff / (xi_fm + xi_ff + xi_ffin), xi_ffin / (xi_fm + xi_ff + xi_ffin)],
        [0, 0, 1]
    ]), DECIMAL)
    print("new transition probability\n", new_transition)
    new_observation = np.around(np.array([
        [gm_m1 / (gm_m1 + gm_m2 + gm_m3), gm_m2 / (gm_m1 + gm_m2 + gm_m3), gm_m3 / (gm_m1 + gm_m2 + gm_m3)],
        [gm_f1 / (gm_f1 + gm_f2 + gm_f3), gm_f2 / (gm_f1 + gm_f2 + gm_f3), gm_f3 / (gm_f1 + gm_f2 + gm_f3)]
    ]), DECIMAL)  # (M, F) * (A, S, H) なので注意
    print("new observation probability\n", new_observation)

if __name__ == "__main__":
    main(sys.argv)
