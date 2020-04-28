import pandas as pd
import matplotlib.pyplot as plt

results = pd.read_csv('/Users/anikajha/Desktop/Numbers/outputFile.csv')
results.plot(x='Size')
plt.show()
