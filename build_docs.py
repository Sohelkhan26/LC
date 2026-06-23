import os
import re
import shutil
from pathlib import Path

# Explicit typing and directory definitions
ROOT_DIR: Path = Path(__file__).parent
SRC_DOCS_DIR: Path = ROOT_DIR / "docs"
PROBLEMS_DIR: Path = SRC_DOCS_DIR / "problems"

# Configuration lists for metadata classification
DIFFICULTIES: list[str] = ["Easy", "Medium", "Hard"]

def sanitize_html_content(content: str) -> str:
    """Cleans up common formatting issues introduced by automated extensions."""
    # Replaces common character entities if needed, ensures text blocks are spaced
    return content

def extract_difficulty(readme_content: str) -> str:
    """Extracts problem difficulty from the markdown file structure."""
    for diff in DIFFICULTIES:
        if f"Difficulty: {diff}" in readme_content or f"Difficulty** {diff}" in readme_content or diff in readme_content.split('\n')[4:10]:
            return diff
    # RegEx fallback scan for badge properties
    match = re.search(r'Difficulty:\s*\*?(\w+)\*?', readme_content, re.IGNORECASE)
    if match and match.group(1).capitalize() in DIFFICULTIES:
        return match.group(1).capitalize()
    return "Unassigned"

def initialize_workspace() -> None:
    """Wipes and resets the staging documentation directory."""
    if SRC_DOCS_DIR.exists():
        shutil.rmtree(SRC_DOCS_DIR)
    PROBLEMS_DIR.mkdir(parents=True, exist_ok=True)
    for diff in DIFFICULTIES + ["Unassigned"]:
        (SRC_DOCS_DIR / "difficulties" / diff.lower()).mkdir(parents=True, exist_ok=True)

def build_knowledge_base() -> None:
    """Iterates through LeetSync folders and generates unified documentation pages."""
    initialize_workspace()
    
    problem_manifest: list[dict] = []
    # Match directories starting with digits (LeetCode problem numbers)
    problem_folder_pattern = re.compile(r"^(\d+)-.*$")

    for folder in ROOT_DIR.iterdir():
        if folder.is_dir() and problem_folder_pattern.match(folder.name):
            readme_path: Path = folder / "README.md"
            if not readme_path.exists():
                continue
                
            with open(readme_path, "r", encoding="utf-8") as f:
                readme_body: str = f.read()
                
            difficulty: str = extract_difficulty(readme_body)
            problem_title: str = folder.name.replace("-", " ").title()
            
            # Locate corresponding solution code file
            code_files: list[Path] = list(folder.glob("*.cpp"))
            code_block: str = ""
            if code_files:
                with open(code_files[0], "r", encoding="utf-8") as f:
                    code_block = f"\n\n## Solution (C++)\n```cpp\n{f.read()}\n```\n"

            # Merge description and implementation code
            compiled_content: str = f"# {problem_title}\n\n" + readme_body + code_block
            
            # Save file to clean problems location
            target_filename: str = f"{folder.name}.md"
            with open(PROBLEMS_DIR / target_filename, "w", encoding="utf-8") as f:
                f.write(compiled_content)
                
            problem_manifest.append({
                "title": problem_title,
                "filename": target_filename,
                "difficulty": difficulty
            })

    # Generate dynamic navigation indices
    generate_indices(problem_manifest)

def generate_indices(manifest: list[dict]) -> None:
    """Creates directory indices and landing pages based on computed metadata."""
    # Generate home landing file
    with open(SRC_DOCS_DIR / "index.md", "w", encoding="utf-8") as f:
        f.write("# LeetCode Complete Algorithmic Index\n\nWelcome to the automated solution base.\n")
        
    # Generate difficulty indexing matrices
    for diff in DIFFICULTIES + ["Unassigned"]:
        diff_lower = diff.lower()
        diff_problems = [p for p in manifest if p["difficulty"] == diff]
        
        index_content = f"# {diff} Problems\n\n"
        for p in diff_problems:
            index_content += f"- [{p['title']}](../../problems/{p['filename']})\n"
            
        with open(SRC_DOCS_DIR / "difficulties" / diff_lower / "index.md", "w", encoding="utf-8") as f:
            f.write(index_content)

if __name__ == "__main__":
    build_knowledge_base()