import time

layers = [
    "Application",
    "Presentation",
    "Session",
    "Transport",
    "Network",
    "Data Link",
    "Physical"
]

print("\nOSI MODEL DATA FLOW\n")

print("ENCAPSULATION\n")

for i, layer in enumerate(layers):
    print(f"{i+1}. {layer}")
    time.sleep(1)

    if (i + 1) % 2 == 0:
        print("Progress...\n")

print("\nSignal Travelling...\n")
time.sleep(2)

print("DECAPSULATION\n")

for i, layer in enumerate(reversed(layers)):
    print(f"{7-i}. {layer}")
    time.sleep(1)

    if (i + 1) % 2 == 0:
        print("Progress...\n")

print("\nMessage Delivered Successfully")