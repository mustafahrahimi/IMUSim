import pandas as pd
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D  # for 3D plots

# Load CSV
df = pd.read_csv("data/outputs/simulation.csv")

# ----------------------------
# 2D Plots (X, Y, Z separately)
# ----------------------------
plt.figure(figsize=(10,6), dpi=300)
plt.plot(df['t'], df['true_x'], label='True X')
plt.plot(df['t'], df['est_x'], label='Estimated X')
plt.plot(df['t'], df['noisy_ax'], label='Noisy Acc X', alpha=0.5)
plt.xlabel('Time (s)')
plt.ylabel('X Position')
plt.title('IMUSim X-axis Simulation')
plt.legend()
plt.grid(True)
plt.savefig("plots/plot_x.png", dpi=300)  
plt.close()  

# ----------------------------
# 3D Trajectory Plot
# ----------------------------
fig = plt.figure(figsize=(10,8), dpi=300)
ax = fig.add_subplot(111, projection='3d')
ax.plot(df['true_x'], df['true_y'], df['true_z'], label='True Trajectory', color='blue')
ax.plot(df['est_x'], df['est_y'], df['est_z'], label='Estimated Trajectory', color='red')
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')
plt.title("IMUSim 3D Trajectory")
plt.legend()
plt.savefig("plots/trajectory_3d.png", dpi=300) 
plt.close()

