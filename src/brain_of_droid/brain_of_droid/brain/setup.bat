@echo off
setlocal

echo Setting up Python 3.11 virtual environment...

:: Check Python 3.11 availability
py -3.11 --version >nul 2>&1
IF %ERRORLEVEL% NEQ 0 (
    echo ERROR: Python 3.11 not found. Please install Python 3.11 and ensure the launcher is configured.
    exit /b 1
)

:: Create virtual environment using Python 3.11
py -3.11 -m venv venv

:: Activate and install dependencies
call venv\Scripts\activate.bat

IF EXIST requirements.txt (
    pip install -r requirements.txt
) ELSE (
    echo No requirements.txt found. Skipping dependency installation.
)

echo.
echo ✅ Setup complete!
echo To activate the environment later, run:
echo     venv\Scripts\activate

endlocal
