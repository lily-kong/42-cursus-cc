#!/usr/bin/env python3

import importlib

libraries = ["pandas", "numpy"]
descriptions = {
    "pandas": "Data manipulation ready",
    "numpy": "Numerical computation ready"
}
missing = False

print()
print("REAGENT STATUS: Loading reagents...")
print()
print("Checking dependencies:")

for name in libraries:
    try:
        module = importlib.import_module(name)
        print(f"[OK] {name} ({module.__version__}) - {descriptions[name]}")
    except ModuleNotFoundError as e:
        if e.name == name:
            missing = True
            print()
            print(f"[MISSING] {name}")
            print(f"Install with pip: pip install {name}")
            print(f"Install with poetry: poetry add {name}")
        else:
            raise

if not missing:
    print()
    print("pip vs Poetry:")
    print(
        "requirements.txt declares what to install; "
        "pip resolves it at install time."
    )
    print(
        "pyproject.toml declares the same constraints, "
        "and Poetry pins the resolved"
    )
    print("versions in poetry.lock so every install is identical.")
    print()
    print("All reagents present and accounted for.")
