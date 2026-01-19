import subprocess
import random
import sys

# Configuration
PUSH_SWAP_PATH = "./push_swap"
CHECKER_PATH = "./checker_linux" 
TOTAL_TESTS = 1000
NUM_COUNT = 500
LIMIT = 5500 if NUM_COUNT == 500 else 700

def run_test(size):
    nums = random.sample(range(-10000, 10000), size)
    args = [str(n) for n in nums]
    arg_string = " ".join(args)

    ps_process = subprocess.Popen([PUSH_SWAP_PATH] + args, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    moves, err = ps_process.communicate()
    
    if err: return None, False, arg_string

    move_list = moves.splitlines()
    move_count = len(move_list)

    check_process = subprocess.Popen([CHECKER_PATH] + args, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    out, _ = check_process.communicate(input=moves)

    is_ok = (out.strip() == "OK")
    return move_count, is_ok, arg_string

def main():
    results = []
    failed_args = []
    over_limit_args = []

    print(f"Testing {NUM_COUNT} numbers. Limit: {LIMIT} operations.")
    
    for i in range(TOTAL_TESTS):
        count, ok, args = run_test(NUM_COUNT)
        
        if not ok or count is None:
            failed_args.append(args)
            print(f"Test {i+1}: KO!                               ")
        elif count > LIMIT:
            over_limit_args.append((count, args))
            results.append(count)
            print(f"Test {i+1}: {count} (OVER LIMIT)              ")
        else:
            results.append(count)
            print(f"Test {i+1}: {count} OK                        ", end='\r')

    print("\n\n--- Final Results ---")
    if results:
        print(f"Average: {sum(results) / len(results):.2f}")
        print(f"Max:     {max(results)}")
    
    if over_limit_args:
        print(f"\n--- {len(over_limit_args)} TESTS EXCEEDED LIMIT ---")
        for count, args in over_limit_args:
            print(f"\n[{count} moves]:\nexport ARG=\"{args}\"")
    
    if failed_args:
        print(f"\n--- {len(failed_args)} TESTS RETURNED KO ---")
        for args in failed_args:
            print(f"\n[KO Case]:\nexport ARG=\"{args}\"")

if __name__ == "__main__":
    main()
