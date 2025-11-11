import os
import sqlite3
import polars as pl
import matplotlib.pyplot as plt
import numpy as np
from scipy.ndimage import uniform_filter1d


# Paths and databases
script_dir = os.path.dirname(os.path.abspath(__file__))
chemins_relatifs = [
    os.path.join(script_dir, "../lang/python/db/"),
    os.path.join(script_dir, "../lang/C/build/db/")
]
noms_bases = [
    "every_number.db",
    "square_iterator.db",
    "square_root_ceil.db"
]


# Go to every paths and database
dataframes = {}
for chemin in chemins_relatifs:
    for nom_base in noms_bases:
        fichier = os.path.join(chemin, nom_base)
        if os.path.exists(fichier):
            chemin_relatif = os.path.relpath(fichier, script_dir)

            # Read sqlite database
            conn = sqlite3.connect(fichier)
            query = "SELECT VALUE, TIME FROM is_prime"
            cursor = conn.cursor()
            cursor.execute(query)
            rows = cursor.fetchall()

            # Convert to polars dataframe
            df = pl.DataFrame({
                "VALUE": [row[0] for row in rows],
                "TIME": [row[1] for row in rows],
            })
            conn.close()
            df = df.with_columns(pl.lit(chemin_relatif).alias("source"))
            dataframes[chemin_relatif] = df

# Verify is dataframes is not null
if not dataframes:
    raise FileNotFoundError("No database find")

# Start plot
plt.figure(figsize=(12, 8))

# Raw data plot
for source, df in dataframes.items():
    values = np.array(df["VALUE"])
    times = np.array(df["TIME"])
    plt.plot(values, times, label=f"{source} (raw)", marker='o', linestyle='none', markersize=3, alpha=0.5)

# Smoothed plot
window_size = 10
for source, df in dataframes.items():
    values = np.array(df["VALUE"])
    times = np.array(df["TIME"])
    smoothed_times = uniform_filter1d(times, size=window_size)
    plt.plot(values, smoothed_times, label=f"{source} (smoothed)", linestyle='-', linewidth=2)

# Plot
plt.xlabel("Values")
plt.ylabel("Time (s)")
plt.yscale('log')
plt.xscale('linear')
plt.title("")
plt.legend(bbox_to_anchor=(1.05, 1), loc='upper left')
plt.grid(True)
plt.tight_layout()

# Save output as png
output_filename = os.path.join(script_dir, "output.png")
plt.savefig(output_filename, dpi=300, bbox_inches='tight')
print(f"\nSaved as : {os.path.join(os.getcwd(), output_filename)}")

# Show plot
plt.show()
