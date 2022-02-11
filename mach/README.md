add-dependencies.sh & README.md originally from https://github.com/hexops/dawn

## Updating

Process for updating Dawn:

1. `git remote add upstream https://dawn.googlesource.com/dawn`
2. `git checkout main && git checkout -B update-nov-30` (replace date with current date)
3. `git fetch upstream && git merge upstream/main`
4. `rm -rf out/ third_party/ build/ && git checkout upstream/main -- third_party/`
5. `gclient sync` At this point there will be quite a large diff as many `third_party/` dependencies we commit will have changed.
6.  Stage and review the changes to the `third_party/` directory by running `./mach/add-dependencies.sh`. Alter the script to include/exclude files as needed, commit the result. Make sure test files, documentation, `.gitmodules`, etc. are not included.
