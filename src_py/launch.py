import subprocess

def launch():
    # Build
    build = subprocess.run(["pio", "run"], capture_output=True, text=True)
    print("Build output:")
    print(build.stdout)
    if build.returncode != 0:
        print("Erro no build:", build.stderr)
        exit(1)

    # Upload
    upload = subprocess.run(["pio", "run", "--target", "upload"], capture_output=True, text=True)
    print("Upload output:")
    print(upload.stdout)
    if upload.returncode != 0:
        print("Erro no upload:", upload.stderr)
        exit(1)