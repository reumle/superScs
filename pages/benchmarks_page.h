/*! \page page_benchmark_results Benchmarks
 * 
 * \tableofcontents
 * 
 * \section benchmarks-dolan-more Dolan-Moré performance profiles
 * 
 * In order to compare different solvers, we employ the [Dolan-Moré performance 
 * profile plot](https://pdfs.semanticscholar.org/54a2/0dbd409436be4f188dfa9a78949a1cac230d.pdf).
 * 
 * Let us briefly introduce the Dolan-Moré performance profile plot. 
 * 
 * Let \f$P\f$ be a finite set of problems used as benchmarks and \f$S\f$ be a 
 * set of solvers we want to compare to one another.
 * 
 * Let \f$t_{p,s}\f$ be the computing cost (e.g., time of flops) to solve a problem 
 * \f$p\f$ using a solver \f$s\f$.
 * 
 * We define the ration between \f$t_{p,s}\f$ and the lowest observed cost to solve
 * this problem using some solver \f$s\in S\f$:
 * 
 * \f{eqnarray*}{
 * r_{p,s} = \frac{t_{p,s}}{\min_{s \in S} t_{p,s}}.
 * \f}
 * 
 * If a solver \f$s\f$ does not solve a problem \f$p\f$, then we assign to \f$r_{p,s}\f$
 * a very high value \f$r_M > r_{p,s}\f$ for all other \f$p,s\f$.
 * 
 * The cumulative distribution of the performance ratio is the Dolan-Moré performance 
 * profile plot.
 * 
 * In particular, define
 * 
 * \f{eqnarray*}{
 * \rho_s(\tau) = \frac{1}{n_p}\#\{p\in P: r_{p,s}\leq \tau\},
 * \f}
 * 
 * for \f$\tau\geq 1\f$ and where \f$n_p\f$ is the number of problems.
 * 
 * The Dolan-Moré performance profile is the plot of \f$\rho_s\f$ vs \f$\tau\f$,
 * typically on a logarithmic x-axis.
 * 
 * <img src="images/dolan-more.png" alt="The Dolan More plot"/>
 * 
 *
 * \section benchmark-results Benchmark results 
 * 
 * \subsection benchmark-parameters Benchmarking parameters
 * 
 * In all benchmark results presented below we set the tolerance of \f$10^{-4}\f$.
 * 
 * The \ref #SCS_SETTINGS.max_iters "maximum number of iterations" was set to a 
 * very high value above which we may confidently tell the problem is unlikely 
 * to be solved (e.g., \f$10^6\f$).
 * 
 * Given that different algorithms (SCS, SuperSCS using Broyden directions and 
 * SuperSCS using Anderson's acceleration) have a different per-iteration cost, 
 * we allow every algorithm to run for a give time (see 
 * \ref #SCS_SETTINGS.max_time_milliseconds "max_time_milliseconds"). 
 * 
 * After that maximum time has passed,
 * if the algorithm has not converged we consider that it has failed to solve the
 * problem.
 * 
 * 
 * 
 * \subsection benchmarks-lasso LASSO problems 
 * 
 * [1152 lasso problems](https://github.com/kul-forbes/scs/blob/master/tests/profiling_matlab/profile_runners/profile_runner_lasso.m)
 * 
 *
 * <div>
 * <table border="0">
 *  <tr>
 *      <td style="padding:1px">
 *          <img src="images/lasso/lasso-broyden-50.png" alt="lasso-broyden-50" width="95%"/>
 *      </td>
 *      <td style="padding:1px">
 *          <img src="images/lasso/lasso-broyden-100.png" alt="lasso-broyden-100" width="95%"/>
 *      </td>
 *      <td style="padding:1px">
 *          <img src="images/lasso/lasso-anderson-5.png" alt="lasso-anderson-5" width="95%"/>
 *      </td>
 *  </tr>
 *  <tr>
 *      <td style="padding:1px">
 *          <img src="images/lasso/lasso-anderson-10.png" alt="lasso-anderson-10" width="95%"/>
 *      </td>
 *      <td style="padding:1px">
 *          <img src="images/lasso/lasso-anderson-15.png" alt="lasso-anderson-15" width="95%"/>
 *      </td>
 *      <td style="padding:1px">
 *          <img src="images/lasso/lasso-anderson-20.png" alt="lasso-anderson-20" width="95%"/>
 *      </td>
 *  </tr>
 * </table>
 * </div>
 * 
 *  
 * \subsection benchmarks-pca1 Regularized PCA
 * 
 * [288 regularized PCA problems](https://github.com/kul-forbes/scs/blob/master/tests/profiling_matlab/profile_runners/profile_runner_pca.m)
 * 
 * <div>
 * <table border="0">
 *  <tr>
 *      <td style="padding:1px">
 *          <img src="images/pca/pca-broyden-100.png" alt="pca-broyden-100" width="93%"/>
 *      </td>
 *      <td style="padding:1px">
 *          <img src="images/pca/pca-anderson-15.png" alt="pca-anderson-15" width="100%"/>
 *      </td>
 *      <td style="padding:1px">
 *          <img src="images/pca/pca-anderson-20.png" alt="pca-anderson-20" width="93%"/>
 *      </td>
 *  </tr>
 * </table>
 * </div>
 * 
 *  
 * \subsection benchmarks-logreg Logistic regression problems
 * 
 * [288 logistic regression problems](https://github.com/kul-forbes/scs/blob/master/tests/profiling_matlab/profile_runners/profile_runner_logreg.m)
 * 
 * <div>
 * <table border="0">
 *  <tr>
 *      <td style="padding:1px">
 *          <img src="images/logreg/logreg-broyden-50.png" alt="logreg-broyden-50" width="95%"/>
 *      </td>
 *      <td style="padding:1px">
 *          <img src="images/logreg/logreg-broyden-100.png" alt="logreg-broyden-100" width="95%"/>
 *      </td>
 *      <td style="padding:1px">
 *          <img src="images/logreg/logreg-anderson-5.png" alt="logreg-anderson-5" width="95%"/>
 *      </td>
 *  </tr>
 *  <tr>
 *      <td style="padding:1px">
 *          <img src="images/logreg/logreg-anderson-10.png" alt="logreg-anderson-10" width="95%"/>
 *      </td>
 *      <td style="padding:1px">
 *          <img src="images/logreg/logreg-anderson-15.png" alt="logreg-anderson-15" width="95%"/>
 *      </td>
 *      <td style="padding:1px">
 *          <img src="images/logreg/logreg-anderson-cmp.png" alt="logreg-anderson-cmp" width="95%"/>
 *      </td>
 *  </tr>
 * </table>
 * </div>
 * 
 * \subsection benchmarks-sdp2 Semidefinite programming
 * 
 * [36 SDP problems](https://github.com/kul-forbes/scs/blob/master/tests/profiling_matlab/profile_runners/profile_runner_sdp2.m)
 * 
 * <div>
 * <table border="0">
 *  <tr>
 *      <td style="padding:1px">
 *          <img src="images/sdp2/sdp2-broyden-50.png" alt="sdp-broyden-50" width="95%"/>
 *      </td>
 *      <td style="padding:1px">
 *          <img src="images/sdp2/sdp2-anderson-10.png" alt="sdp2-anderson-10" width="95%"/>
 *      </td>
 *      <td style="padding:1px">
 *          <img src="images/sdp2/sdp2-anderson-15.png" alt="sdp2-anderson-15" width="90%"/>
 *      </td>
 *  </tr>
 * </table>
 * </div>
 * 
 * \subsection benchmarks-normcon Norm-constrained norm minimization
 * 
 * [384 norm-constrained problems](https://github.com/kul-forbes/scs/blob/master/tests/profiling_matlab/profile_runners/profile_runner_normcon.m)
 * 
 * <div>
 * <table border="0">
 *  <tr>
 *      <td style="padding:1px">
 *          <img src="images/normcon/normcon-broyden-50.png" alt="normcon-broyden-50" width="95%"/>
 *      </td>
 *      <td style="padding:1px">
 *          <img src="images/normcon/normcon-broyden-100.png" alt="normcon-broyden-100" width="95%"/>
 *      </td>
 *      <td style="padding:1px">
 *          <img src="images/normcon/normcon-anderson-5.png" alt="normcon-anderson-5" width="90%"/>
 *      </td>
 *  </tr>
 * </table>
 * </div>
 * 
 * \section maros-meszaros Maros-Meszaros Problems
 * 
 * We tested SuperSCS on the 
 * [Maros-Meszaros collection of QP problems](http://www.cuter.rl.ac.uk/Problems/marmes.html).
 * 
 * <div>
 * <table border="0">
 *  <tr>
 *      <td style="padding:1px">
 *          <img src="images/mm/mm-scs-vs-bro.png" alt="Maros-Meszaros: SCS vs SuperSCS/Broyden" width="95%"/>
 *      </td>
 *      <td style="padding:1px">
 *          <img src="images/mm/mm-scs-vs-aa.png" alt="Maros-Meszaros: SCS vs SuperSCS/AA" width="95%"/>
 *      </td>
 *      <td style="padding:1px">
 *          <img src="images/mm/mm-aa-vs-bro.png" alt="Maros-Meszaros: SuperSCS Broyden vs AA" width="95%"/>
 *      </td>
 *  </tr>
 * </table>
 * </div>
 * 
 * Find details \ref page_maros_meszaros_results "here".
 */