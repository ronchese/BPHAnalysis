import FWCore.ParameterSet.Config as cms

process = cms.Process("bphAnalysis")

#process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(1000) )

process.load("Configuration.Geometry.GeometryRecoDB_cff")
process.load("Configuration.StandardSequences.MagneticField_cff")
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.EventContent.EventContent_cff')
process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load('Configuration.StandardSequences.MagneticField_AutoFromDBCurrent_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')
process.load("TrackingTools/TransientTrack/TransientTrackBuilder_cfi")

process.CandidateSelectedTracks = cms.EDProducer( "ConcreteChargedCandidateProducer",
                src=cms.InputTag("oniaSelectedTracks::RECO"),
                particleType=cms.string('pi+')
)

from PhysicsTools.PatAlgos.producersLayer1.genericParticleProducer_cfi import patGenericParticles
process.patSelectedTracks = patGenericParticles.clone(src=cms.InputTag("CandidateSelectedTracks"))

process.MessageLogger.cerr.FwkReport.reportEvery = 100
process.options = cms.untracked.PSet( wantSummary = cms.untracked.bool(True) )
process.options.allowUnscheduled = cms.untracked.bool(True)

process.source = cms.Source("PoolSource",fileNames = cms.untracked.vstring(
#
### use this to access the nearest copy of the input file, querying the catalog
#
'/store/data/Run2018D/Charmonium/USER/BPHSkim-PromptReco-v2/000/325/100/00000/0C1876EF-1F35-EC43-A6E9-415EA449DD45.root'
#'/store/data/Run2017C/Charmonium/USER/BPHSkim-12Sep2017-v1/310000/5CB5C64A-DBA9-E711-8FEA-02163E0165E2.root'
    #'/store/data/Run2016E/Charmonium/USER/BPHSkim-PromptReco-v2/000/276/831/00000/00FD1519-714D-E611-B686-FA163E321AE0.root'
### use this to access the input file if by any reason you want to specify 
### the data server
#    'root://xrootd-cms.infn.it//store/data/Run2016E/Charmonium/USER/BPHSkim-PromptReco-v2/000/276/831/00000/00FD1519-714D-E611-B686-FA163E321AE0.root'
#
### use this to access an input file locally available
#    'file:/...complete_file_path.../XXXX.root'
))

from Configuration.AlCa.GlobalTag_condDBv2 import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, 'auto:run2_data', '')

process.testBPHRecoDecay = cms.EDAnalyzer('TestBPHRecoDecay',
    gpCandsLabel = cms.string('patSelectedTracks'),
    ccCandsLabel = cms.string('onia2MuMuPAT::RECO'),
    outDump = cms.string('dump_skim.txt'),
    outHist = cms.string('hist_skim.root')
)

process.p = cms.Path(
    process.testBPHRecoDecay
)

