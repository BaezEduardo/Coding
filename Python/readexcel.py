import pandas as pd

#data = pd.read_excel("Python/20180401_pump_sensor_data.xlsx")
#data = pd.read_excel("Python/Workday.xlsx",index_col=[0])
data = pd.read_csv("Python/cont.txt", delim_whitespace=True)

data.head()