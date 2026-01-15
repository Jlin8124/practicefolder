import numpy as np
import pandas as pd
import matplotlib.pyplot as plt 
import yfinance as yf

rets = yf.download(tickers='SPY', interval='1mo')["Adj Close"]

type(rets)

#adj close gives us casflows inclusive of dividends and coupons so price does not drop when a dividend is paid
#you did not lose whatever amount was paid in returns

s = pd.Series(np.random.randn(5), index = ['a', 'b', 'c', 'd', 'e'])

print(s)

d = {'name': 'Jason', 'age': '25'}
print(d)
print(d)
print(d)

pd.Series(d)

print(d)

#why would you instantiate a series from a dict? because a dict has no order


