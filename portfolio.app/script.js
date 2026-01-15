import { useMemo } from "react";

const BestPortfolioComponent = ({ totalStartups, pickCount }) => {
  const possibilities = useMemo(() => {
    // 1. Use BigInt for safety
    let n = BigInt(totalStartups);
    let k = BigInt(pickCount);
    
    // 2. Optimization
    if (k > n / 2n) k = n - k;

    let res = 1n;
    for (let i = 1n; i <= k; i++) {
        // 3. CORRECT MATH (Divide by i, not 1)
        res = res * (n - i + 1n) / i; 
    }

    // 4. Return string (React can't render BigInt directly)
    return res.toString();
  }, [totalStartups, pickCount]);

  return (
    <div>{possibilities} combinations</div>
  );
};