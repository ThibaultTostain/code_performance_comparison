# Python project

## Project structure
```plaintext
📁 python/                # Main folder for the project
├── 📁 .venv/             # Python virtual environnement (not tracked by Git)
├── 📁 db/                # Database output (not tracked by Git)
├── 📁 lib/               # Librairie
│   ├── 📁 __pycache__/   # Bytecode (not tracked by Git)
│   ├── 🐍 compute.py     # Time compute
│   ├── 🐍 database.py    # Database gestion
│   └── 🐍 functions.py   # Prime validation
├── 🐍 main.py            # main file
├── 📄 README.md          # README specific to the project
└── 💲 setup.bash          # setup the project
```

## How to run the project

Setup the project :
```bash
./setup.bash
.venv/bin/activate
```

Run the project :
```bash
python main.py
```

## Time measurement
Time can be precise to .37f with `time.perf_counter()` and it a bit faster than `time.time()`.